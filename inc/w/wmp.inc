' ########################################################################################
' Microsoft Windows
' File: wmp.inc
' Contents: Windows Media Player
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WMPLib
' Version: 1.0, Locale ID = 0
' Description: Windows Media Player
' Path: C:\WINDOWS\system32\wmp.dll
' Library GUID: {6BF52A50-394A-11D3-B153-00C04F79FAA6}
' ########################################################################################

#INCLUDE THIS ONCE
%WMP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {6BF52A52-394A-11D3-B153-00C04F79FAA6}
$PROGID_WindowsMediaPlayer7 = "WMPlayer.OCX.7"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {6BF52A52-394A-11D3-B153-00C04F79FAA6}
$PROGID_WindowsMediaPlayer = "WMPlayer.OCX"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_WindowsMediaPlayer       = GUID$("{6BF52A52-394A-11D3-B153-00C04F79FAA6}")
$CLSID_WMPSkinManager           = GUID$("{B2A7FD52-301F-4348-B93A-638C6DE49229}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IWMPCdrom                  = GUID$("{CFAB6E98-8730-11D3-B388-00C04F68574B}")
$IID_IWMPCdromBurn              = GUID$("{BD94DBEB-417F-4928-AA06-087D56ED9B59}")
$IID_IWMPCdromCollection        = GUID$("{EE4C8FE2-34B2-11D3-A3BF-006097C9B344}")
$IID_IWMPCdromRip               = GUID$("{56E2294F-69ED-4629-A869-AEA72C0DCC2C}")
$IID_IWMPClosedCaption          = GUID$("{4F2DF574-C588-11D3-9ED0-00C04FB6E937}")
$IID_IWMPClosedCaption2         = GUID$("{350BA78B-6BC8-4113-A5F5-312056934EB6}")
$IID_IWMPControls               = GUID$("{74C09E02-F828-11D2-A74B-00A0C905F36E}")
$IID_IWMPControls2              = GUID$("{6F030D25-0890-480F-9775-1F7E40AB5B8E}")
$IID_IWMPControls3              = GUID$("{A1D1110E-D545-476A-9A78-AC3E4CB1E6BD}")
$IID_IWMPCore                   = GUID$("{D84CCA99-CCE2-11D2-9ECC-0000F8085981}")
$IID_IWMPCore2                  = GUID$("{BC17E5B7-7561-4C18-BB90-17D485775659}")
$IID_IWMPCore3                  = GUID$("{7587C667-628F-499F-88E7-6A6F4E888464}")
$IID_IWMPDVD                    = GUID$("{8DA61686-4668-4A5C-AE5D-803193293DBE}")
$IID_IWMPError                  = GUID$("{A12DCF7D-14AB-4C1B-A8CD-63909F06025B}")
$IID_IWMPErrorItem              = GUID$("{3614C646-3B3B-4DE7-A81E-930E3F2127B3}")
$IID_IWMPErrorItem2             = GUID$("{F75CCEC0-C67C-475C-931E-8719870BEE7D}")
$IID_IWMPEvents                 = GUID$("{19A6627B-DA9E-47C1-BB23-00B5E668236A}")
$IID_IWMPEvents2                = GUID$("{1E7601FA-47EA-4107-9EA9-9004ED9684FF}")
$IID_IWMPEvents3                = GUID$("{1F504270-A66B-4223-8E96-26A06C63D69F}")
$IID_IWMPEvents4                = GUID$("{26DABCFA-306B-404D-9A6F-630A8405048D}")
$IID_IWMPFolderMonitorServices  = GUID$("{788C8743-E57F-439D-A468-5BC77F2E59C6}")
$IID_IWMPLibrary                = GUID$("{3DF47861-7DF1-4C1F-A81B-4C26F0F7A7C6}")
$IID_IWMPLibrary2               = GUID$("{DD578A4E-79B1-426C-BF8F-3ADD9072500B}")
$IID_IWMPLibraryServices        = GUID$("{39C2F8D5-1CF2-4D5E-AE09-D73492CF9EAA}")
$IID_IWMPLibrarySharingServices = GUID$("{82CBA86B-9F04-474B-A365-D6DD1466E541}")
$IID_IWMPMedia                  = GUID$("{94D55E95-3FAC-11D3-B155-00C04F79FAA6}")
$IID_IWMPMedia2                 = GUID$("{AB7C88BB-143E-4EA4-ACC3-E4350B2106C3}")
$IID_IWMPMedia3                 = GUID$("{F118EFC7-F03A-4FB4-99C9-1C02A5C1065B}")
$IID_IWMPMediaCollection        = GUID$("{8363BC22-B4B4-4B19-989D-1CD765749DD1}")
$IID_IWMPMediaCollection2       = GUID$("{8BA957F5-FD8C-4791-B82D-F840401EE474}")
$IID_IWMPMetadataPicture        = GUID$("{5C29BBE0-F87D-4C45-AA28-A70F0230FFA9}")
$IID_IWMPMetadataText           = GUID$("{769A72DB-13D2-45E2-9C48-53CA9D5B7450}")
$IID_IWMPNetwork                = GUID$("{EC21B779-EDEF-462D-BBA4-AD9DDE2B29A7}")
$IID_IWMPPlayer                 = GUID$("{6BF52A4F-394A-11D3-B153-00C04F79FAA6}")
$IID_IWMPPlayer2                = GUID$("{0E6B01D1-D407-4C85-BF5F-1C01F6150280}")
$IID_IWMPPlayer3                = GUID$("{54062B68-052A-4C25-A39F-8B63346511D4}")
$IID_IWMPPlayer4                = GUID$("{6C497D62-8919-413C-82DB-E935FB3EC584}")
$IID_IWMPPlayerApplication      = GUID$("{40897764-CEAB-47BE-AD4A-8E28537F9BBF}")
$IID_IWMPPlayerServices         = GUID$("{1D01FBDB-ADE2-4C8D-9842-C190B95C3306}")
$IID_IWMPPlayerServices2        = GUID$("{1BB1592F-F040-418A-9F71-17C7512B4D70}")
$IID_IWMPPlaylist               = GUID$("{D5F0F4F1-130C-11D3-B14E-00C04F79FAA6}")
$IID_IWMPPlaylistArray          = GUID$("{679409C0-99F7-11D3-9FB7-00105AA620BB}")
$IID_IWMPPlaylistCollection     = GUID$("{10A13217-23A7-439B-B1C0-D847C79B7774}")
$IID_IWMPQuery                  = GUID$("{A00918F3-A6B0-4BFB-9189-FD834C7BC5A5}")
$IID_IWMPRemoteMediaServices    = GUID$("{CBB92747-741F-44FE-AB5B-F1A48F3B2A59}")
$IID_IWMPSettings               = GUID$("{9104D1AB-80C9-4FED-ABF0-2E6417A6DF14}")
$IID_IWMPSettings2              = GUID$("{FDA937A4-EECE-4DA5-A0B6-39BF89ADE2C2}")
$IID_IWMPSkinManager            = GUID$("{076F2FA6-ED30-448B-8CC5-3F3EF3529C7A}")
$IID_IWMPStringCollection       = GUID$("{4A976298-8C0D-11D3-B389-00C04F68574B}")
$IID_IWMPStringCollection2      = GUID$("{46AD648D-53F1-4A74-92E2-2A1B68D63FD4}")
$IID_IWMPSyncDevice             = GUID$("{82A2986C-0293-4FD0-B279-B21B86C058BE}")
$IID_IWMPSyncDevice2            = GUID$("{88AFB4B2-140A-44D2-91E6-4543DA467CD1}")
$IID_IWMPSyncDevice3            = GUID$("{B22C85F9-263C-4372-A0DA-B518DB9B4098}")
$IID_IWMPSyncServices           = GUID$("{8B5050FF-E0A4-4808-B3A8-893A9E1ED894}")
$IID__WMPOCXEvents              = GUID$("{6BF52A51-394A-11D3-B153-00C04F79FAA6}")

' ========================================================================================
' WMPOpenState enum
' State of opening process
' ========================================================================================

%wmposUndefined               = 0
%wmposPlaylistChanging        = %wmposUndefined               + 1
%wmposPlaylistLocating        = %wmposPlaylistChanging        + 1
%wmposPlaylistConnecting      = %wmposPlaylistLocating        + 1
%wmposPlaylistLoading         = %wmposPlaylistConnecting      + 1
%wmposPlaylistOpening         = %wmposPlaylistLoading         + 1
%wmposPlaylistOpenNoMedia     = %wmposPlaylistOpening         + 1
%wmposPlaylistChanged         = %wmposPlaylistOpenNoMedia     + 1
%wmposMediaChanging           = %wmposPlaylistChanged         + 1
%wmposMediaLocating           = %wmposMediaChanging           + 1
%wmposMediaConnecting         = %wmposMediaLocating           + 1
%wmposMediaLoading            = %wmposMediaConnecting         + 1
%wmposMediaOpening            = %wmposMediaLoading            + 1
%wmposMediaOpen               = %wmposMediaOpening            + 1
%wmposBeginCodecAcquisition   = %wmposMediaOpen               + 1
%wmposEndCodecAcquisition     = %wmposBeginCodecAcquisition   + 1
%wmposBeginLicenseAcquisition = %wmposEndCodecAcquisition     + 1
%wmposEndLicenseAcquisition   = %wmposBeginLicenseAcquisition + 1
%wmposBeginIndividualization  = %wmposEndLicenseAcquisition   + 1
%wmposEndIndividualization    = %wmposBeginIndividualization  + 1
%wmposMediaWaiting            = %wmposEndIndividualization    + 1
%wmposOpeningUnknownURL       = %wmposMediaWaiting            + 1

' ========================================================================================
' WMPPlayState enum
' State of playback
' ========================================================================================

%wmppsUndefined               = 0
%wmppsStopped                 = %wmppsUndefined               + 1
%wmppsPaused                  = %wmppsStopped                 + 1
%wmppsPlaying                 = %wmppsPaused                  + 1
%wmppsScanForward             = %wmppsPlaying                 + 1
%wmppsScanReverse             = %wmppsScanForward             * 1
%wmppsBuffering               = %wmppsScanReverse             + 1
%wmppsWaiting                 = %wmppsBuffering               + 1
%wmppsMediaEnded              = %wmppsWaiting                 + 1
%wmppsTransitioning           = %wmppsMediaEnded              + 1
%wmppsReady                   = %wmppsTransitioning           + 1
%wmppsReconnecting            = %wmppsReady                   + 1
%wmppsLast                    = %wmppsReconnecting            + 1

' ========================================================================================
' WMPPlaylistChangeEventType enum
' WMP Playlist Change Event Type
' ========================================================================================

%wmplcUnknown                 = 0
%wmplcClear                   = %wmplcUnknown                 + 1
%wmplcInfoChange              = %wmplcClear                   + 1
%wmplcMove                    = %wmplcInfoChange              + 1
%wmplcDelete                  = %wmplcMove                    + 1
%wmplcInsert                  = %wmplcDelete                  + 1
%wmplcAppend                  = %wmplcInsert                  + 1
%wmplcPrivate                 = %wmplcAppend                  + 1
%wmplcNameChange              = %wmplcPrivate                 + 1
%wmplcMorph                   = %wmplcNameChange              + 1
%wmplcSort                    = %wmplcMorph                   + 1
%wmplcLast                    = %wmplcSort                    + 1

' ########################################################################################
' Interface name = IWMPErrorItem
' IID = {3614C646-3B3B-4DE7-A81E-930E3F2127B3}
' IWMPErrorItem: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPErrorItem_INTERFACE_DEFINED)
    %IWMPErrorItem_INTERFACE_DEFINED = 1

INTERFACE IWMPErrorItem $IID_IWMPErrorItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET errorCode <901> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *phr
   ' =====================================================================================
   PROPERTY GET errorDescription <902> ( _              ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY GET errorContext <903> ( _                  ' VTable offset = 36
   ) AS VARIANT                                         ' __out_retval VARIANT *pvarContext
   ' =====================================================================================
   PROPERTY GET remedy <904> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __out_retval long *plRemedy
   ' =====================================================================================
   PROPERTY GET customUrl <905> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrCustomUrl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPErrorItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPError
' IID = {A12DCF7D-14AB-4C1B-A8CD-63909F06025B}
' IWMPError: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPError_INTERFACE_DEFINED)
    %IWMPError_INTERFACE_DEFINED = 1

INTERFACE IWMPError $IID_IWMPError

   INHERIT IDispatch

   ' =====================================================================================
   METHOD clearErrorQueue <851> ( _                     ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET errorCount <852> ( _                    ' VTable offset = 32
   ) AS LONG                                            ' __out_retval long *plNumErrors
   ' =====================================================================================
   PROPERTY GET Item <853> ( _                          ' VTable offset = 36
     BYVAL dwIndex AS LONG _                            ' __in long dwIndex
   ) AS IWMPErrorItem                                   ' __out_retval IWMPErrorItem **ppErrorItem
   ' =====================================================================================
   METHOD webHelp <854> ( _                             ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPError_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPMedia
' IID = {94D55E95-3FAC-11D3-B155-00C04F79FAA6}
' IWMPMedia: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPMedia_INTERFACE_DEFINED)
    %IWMPMedia_INTERFACE_DEFINED = 1

INTERFACE IWMPMedia $IID_IWMPMedia

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET isIdentical <763> ( _                   ' VTable offset = 28
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================
   PROPERTY GET sourceURL <751> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSourceURL
   ' =====================================================================================
   PROPERTY GET name <764> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET name <764> ( _                          ' VTable offset = 40
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET imageSourceWidth <752> ( _              ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *pWidth
   ' =====================================================================================
   PROPERTY GET imageSourceHeight <753> ( _             ' VTable offset = 48
   ) AS LONG                                            ' __out_retval long *pHeight
   ' =====================================================================================
   PROPERTY GET markerCount <754> ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __out_retval long *pMarkerCount
   ' =====================================================================================
   METHOD getMarkerTime <755> ( _                       ' VTable offset = 56
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS DOUBLE                                          ' __out_retval double *pMarkerTime
   ' =====================================================================================
   METHOD getMarkerName <756> ( _                       ' VTable offset = 60
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMarkerName
   ' =====================================================================================
   PROPERTY GET duration <757> ( _                      ' VTable offset = 64
   ) AS DOUBLE                                          ' __out_retval double *pDuration
   ' =====================================================================================
   PROPERTY GET durationString <758> ( _                ' VTable offset = 68
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDuration
   ' =====================================================================================
   PROPERTY GET attributeCount <759> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getAttributeName <760> ( _                    ' VTable offset = 76
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrItemName
   ' =====================================================================================
   METHOD getItemInfo <761> ( _                         ' VTable offset = 80
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD setItemInfo <762> ( _                         ' VTable offset = 84
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   METHOD getItemInfoByAtom <765> ( _                   ' VTable offset = 88
     BYVAL lAtom AS LONG _                              ' __in long lAtom
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD isMemberOf <766> ( _                          ' VTable offset = 92
     BYVAL pPlaylist AS IWMPPlaylist _                  ' __in IWMPPlaylist *pPlaylist
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsMemberOf
   ' =====================================================================================
   METHOD isReadOnlyItem <767> ( _                      ' VTable offset = 96
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsReadOnly
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPMedia_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPControls
' IID = {74C09E02-F828-11D2-A74B-00A0C905F36E}
' IWMPControls: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPControls_INTERFACE_DEFINED)
    %IWMPControls_INTERFACE_DEFINED = 1

INTERFACE IWMPControls $IID_IWMPControls

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET isAvailable <62> ( _                    ' VTable offset = 28
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pIsAvailable
   ' =====================================================================================
   METHOD play <51> ( _                                 ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD stop <52> ( _                                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD pause <53> ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD fastForward <54> ( _                          ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD fastReverse <55> ( _                          ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPosition <56> ( _                ' VTable offset = 52
   ) AS DOUBLE                                          ' __out_retval double *pdCurrentPosition
   ' =====================================================================================
   PROPERTY SET currentPosition <56> ( _                ' VTable offset = 56
     BYVAL pdCurrentPosition AS DOUBLE _                ' __in double pdCurrentPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPositionString <57> ( _          ' VTable offset = 60
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrCurrentPosition
   ' =====================================================================================
   METHOD next <58> ( _                                 ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD previous <59> ( _                             ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentItem <60> ( _                    ' VTable offset = 72
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppIWMPMedia
   ' =====================================================================================
   PROPERTY SET currentItem <60> ( _                    ' VTable offset = 76
     BYVAL ppIWMPMedia AS IWMPMedia _                   ' __in IWMPMedia *ppIWMPMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentMarker <61> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __out_retval long *plMarker
   ' =====================================================================================
   PROPERTY SET currentMarker <61> ( _                  ' VTable offset = 84
     BYVAL plMarker AS LONG _                           ' __in long plMarker
   )                                                    ' void
   ' =====================================================================================
   METHOD playItem <63> ( _                             ' VTable offset = 88
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPControls_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPSettings
' IID = {9104D1AB-80C9-4FED-ABF0-2E6417A6DF14}
' IWMPSettings: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPSettings_INTERFACE_DEFINED)
    %IWMPSettings_INTERFACE_DEFINED = 1

INTERFACE IWMPSettings $IID_IWMPSettings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET isAvailable <113> ( _                   ' VTable offset = 28
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pIsAvailable
   ' =====================================================================================
   PROPERTY GET autoStart <101> ( _                     ' VTable offset = 32
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfAutoStart
   ' =====================================================================================
   PROPERTY SET autoStart <101> ( _                     ' VTable offset = 36
     BYVAL pfAutoStart AS INTEGER _                     ' __in VARIANT_BOOL pfAutoStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET baseURL <108> ( _                       ' VTable offset = 40
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrBaseURL
   ' =====================================================================================
   PROPERTY SET baseURL <108> ( _                       ' VTable offset = 44
     BYVAL pbstrBaseURL AS WSTRING _                    ' __in BSTR pbstrBaseURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET defaultFrame <109> ( _                  ' VTable offset = 48
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDefaultFrame
   ' =====================================================================================
   PROPERTY SET defaultFrame <109> ( _                  ' VTable offset = 52
     BYVAL pbstrDefaultFrame AS WSTRING _               ' __in BSTR pbstrDefaultFrame
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET invokeURLs <103> ( _                    ' VTable offset = 56
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfInvokeURLs
   ' =====================================================================================
   PROPERTY SET invokeURLs <103> ( _                    ' VTable offset = 60
     BYVAL pfInvokeURLs AS INTEGER _                    ' __in VARIANT_BOOL pfInvokeURLs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mute <104> ( _                          ' VTable offset = 64
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfMute
   ' =====================================================================================
   PROPERTY SET mute <104> ( _                          ' VTable offset = 68
     BYVAL pfMute AS INTEGER _                          ' __in VARIANT_BOOL pfMute
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET playCount <105> ( _                     ' VTable offset = 72
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   PROPERTY SET playCount <105> ( _                     ' VTable offset = 76
     BYVAL plCount AS LONG _                            ' __in long plCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rate <106> ( _                          ' VTable offset = 80
   ) AS DOUBLE                                          ' __out_retval double *pdRate
   ' =====================================================================================
   PROPERTY SET rate <106> ( _                          ' VTable offset = 84
     BYVAL pdRate AS DOUBLE _                           ' __in double pdRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET balance <102> ( _                       ' VTable offset = 88
   ) AS LONG                                            ' __out_retval long *plBalance
   ' =====================================================================================
   PROPERTY SET balance <102> ( _                       ' VTable offset = 92
     BYVAL plBalance AS LONG _                          ' __in long plBalance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET volume <107> ( _                        ' VTable offset = 96
   ) AS LONG                                            ' __out_retval long *plVolume
   ' =====================================================================================
   PROPERTY SET volume <107> ( _                        ' VTable offset = 100
     BYVAL plVolume AS LONG _                           ' __in long plVolume
   )                                                    ' void
   ' =====================================================================================
   METHOD getMode <110> ( _                             ' VTable offset = 104
     BYVAL bstrMode AS WSTRING _                        ' __in BSTR bstrMode
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfMode
   ' =====================================================================================
   METHOD setMode <111> ( _                             ' VTable offset = 108
     BYVAL bstrMode AS WSTRING _                        ' __in BSTR bstrMode
   , BYVAL varfMode AS INTEGER _                        ' __in VARIANT_BOOL varfMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET enableErrorDialogs <112> ( _            ' VTable offset = 112
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfEnableErrorDialogs
   ' =====================================================================================
   PROPERTY SET enableErrorDialogs <112> ( _            ' VTable offset = 116
     BYVAL pfEnableErrorDialogs AS INTEGER _            ' __in VARIANT_BOOL pfEnableErrorDialogs
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPSettings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPClosedCaption
' IID = {4F2DF574-C588-11D3-9ED0-00C04FB6E937}
' IWMPClosedCaption: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPClosedCaption_INTERFACE_DEFINED)
    %IWMPClosedCaption_INTERFACE_DEFINED = 1

INTERFACE IWMPClosedCaption $IID_IWMPClosedCaption

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SAMIStyle <951> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSAMIStyle
   ' =====================================================================================
   PROPERTY SET SAMIStyle <951> ( _                     ' VTable offset = 32
     BYVAL pbstrSAMIStyle AS WSTRING _                  ' __in BSTR pbstrSAMIStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SAMILang <952> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSAMILang
   ' =====================================================================================
   PROPERTY SET SAMILang <952> ( _                      ' VTable offset = 40
     BYVAL pbstrSAMILang AS WSTRING _                   ' __in BSTR pbstrSAMILang
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SAMIFileName <953> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSAMIFileName
   ' =====================================================================================
   PROPERTY SET SAMIFileName <953> ( _                  ' VTable offset = 48
     BYVAL pbstrSAMIFileName AS WSTRING _               ' __in BSTR pbstrSAMIFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET captioningId <954> ( _                  ' VTable offset = 52
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrCaptioningID
   ' =====================================================================================
   PROPERTY SET captioningId <954> ( _                  ' VTable offset = 56
     BYVAL pbstrCaptioningID AS WSTRING _               ' __in BSTR pbstrCaptioningID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPClosedCaption_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlaylist
' IID = {D5F0F4F1-130C-11D3-B14E-00C04F79FAA6}
' IWMPPlaylist: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPPlaylist_INTERFACE_DEFINED)
    %IWMPPlaylist_INTERFACE_DEFINED = 1

INTERFACE IWMPPlaylist $IID_IWMPPlaylist

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET count <201> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   PROPERTY GET name <202> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET name <202> ( _                          ' VTable offset = 36
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET attributeCount <210> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   PROPERTY GET attributeName <211> ( _                 ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrAttributeName
   ' =====================================================================================
   PROPERTY GET Item <212> ( _                          ' VTable offset = 48
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppIWMPMedia
   ' =====================================================================================
   METHOD getItemInfo <203> ( _                         ' VTable offset = 52
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD setItemInfo <204> ( _                         ' VTable offset = 56
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET isIdentical <213> ( _                   ' VTable offset = 60
     BYVAL pIWMPPlaylist AS IWMPPlaylist _              ' __in IWMPPlaylist *pIWMPPlaylist
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================
   METHOD clear <205> ( _                               ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD insertItem <206> ( _                          ' VTable offset = 68
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   , BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   )                                                    ' void
   ' =====================================================================================
   METHOD appendItem <207> ( _                          ' VTable offset = 72
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   )                                                    ' void
   ' =====================================================================================
   METHOD removeItem <208> ( _                          ' VTable offset = 76
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   )                                                    ' void
   ' =====================================================================================
   METHOD moveItem <209> ( _                            ' VTable offset = 80
     BYVAL lIndexOld AS LONG _                          ' __in long lIndexOld
   , BYVAL lIndexNew AS LONG _                          ' __in long lIndexNew
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlaylist_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPCdrom
' IID = {CFAB6E98-8730-11D3-B388-00C04F68574B}
' IWMPCdrom: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPCdrom_INTERFACE_DEFINED)
    %IWMPCdrom_INTERFACE_DEFINED = 1

INTERFACE IWMPCdrom $IID_IWMPCdrom

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET driveSpecifier <251> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDrive
   ' =====================================================================================
   PROPERTY GET Playlist <252> ( _                      ' VTable offset = 32
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPlaylist
   ' =====================================================================================
   METHOD eject <253> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPCdrom_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPCdromCollection
' IID = {EE4C8FE2-34B2-11D3-A3BF-006097C9B344}
' IWMPCdromCollection: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPCdromCollection_INTERFACE_DEFINED)
    %IWMPCdromCollection_INTERFACE_DEFINED = 1

INTERFACE IWMPCdromCollection $IID_IWMPCdromCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET count <301> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD Item <302> ( _                                ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IWMPCdrom                                       ' __out_retval IWMPCdrom **ppItem
   ' =====================================================================================
   METHOD getByDriveSpecifier <303> ( _                 ' VTable offset = 36
     BYVAL bstrDriveSpecifier AS WSTRING _              ' __in BSTR bstrDriveSpecifier
   ) AS IWMPCdrom                                       ' __out_retval IWMPCdrom **ppCdrom
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPCdromCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPStringCollection
' IID = {4A976298-8C0D-11D3-B389-00C04F68574B}
' IWMPStringCollection: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPStringCollection_INTERFACE_DEFINED)
    %IWMPStringCollection_INTERFACE_DEFINED = 1

INTERFACE IWMPStringCollection $IID_IWMPStringCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET count <401> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD Item <402> ( _                                ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPStringCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPMediaCollection
' IID = {8363BC22-B4B4-4B19-989D-1CD765749DD1}
' IWMPMediaCollection: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPMediaCollection_INTERFACE_DEFINED)
    %IWMPMediaCollection_INTERFACE_DEFINED = 1

INTERFACE IWMPMediaCollection $IID_IWMPMediaCollection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD add <452> ( _                                 ' VTable offset = 28
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppItem
   ' =====================================================================================
   METHOD getAll <453> ( _                              ' VTable offset = 32
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByName <454> ( _                           ' VTable offset = 36
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByGenre <455> ( _                          ' VTable offset = 40
     BYVAL bstrGenre AS WSTRING _                       ' __in BSTR bstrGenre
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByAuthor <456> ( _                         ' VTable offset = 44
     BYVAL bstrAuthor AS WSTRING _                      ' __in BSTR bstrAuthor
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByAlbum <457> ( _                          ' VTable offset = 48
     BYVAL bstrAlbum AS WSTRING _                       ' __in BSTR bstrAlbum
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByAttribute <458> ( _                      ' VTable offset = 52
     BYVAL bstrAttribute AS WSTRING _                   ' __in BSTR bstrAttribute
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD remove <459> ( _                              ' VTable offset = 56
     BYVAL pItem AS IWMPMedia _                         ' __in IWMPMedia *pItem
   , BYVAL varfDeleteFile AS INTEGER _                  ' __in VARIANT_BOOL varfDeleteFile
   )                                                    ' void
   ' =====================================================================================
   METHOD getAttributeStringCollection <461> ( _        ' VTable offset = 60
     BYVAL bstrAttribute AS WSTRING _                   ' __in BSTR bstrAttribute
   , BYVAL bstrMediaType AS WSTRING _                   ' __in BSTR bstrMediaType
   ) AS IWMPStringCollection                            ' __out_retval IWMPStringCollection **ppStringCollection
   ' =====================================================================================
   METHOD getMediaAtom <470> ( _                        ' VTable offset = 64
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS LONG                                            ' __out_retval long *plAtom
   ' =====================================================================================
   METHOD setDeleted <471> ( _                          ' VTable offset = 68
     BYVAL pItem AS IWMPMedia _                         ' __in IWMPMedia *pItem
   , BYVAL varfIsDeleted AS INTEGER _                   ' __in VARIANT_BOOL varfIsDeleted
   )                                                    ' void
   ' =====================================================================================
   METHOD isDeleted <472> ( _                           ' VTable offset = 72
     BYVAL pItem AS IWMPMedia _                         ' __in IWMPMedia *pItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsDeleted
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPMediaCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlaylistArray
' IID = {679409C0-99F7-11D3-9FB7-00105AA620BB}
' IWMPPlaylistArray: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPPlaylistArray_INTERFACE_DEFINED)
    %IWMPPlaylistArray_INTERFACE_DEFINED = 1

INTERFACE IWMPPlaylistArray $IID_IWMPPlaylistArray

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET count <501> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD Item <502> ( _                                ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppItem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlaylistArray_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlaylistCollection
' IID = {10A13217-23A7-439B-B1C0-D847C79B7774}
' IWMPPlaylistCollection: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPPlaylistCollection_INTERFACE_DEFINED)
    %IWMPPlaylistCollection_INTERFACE_DEFINED = 1

INTERFACE IWMPPlaylistCollection $IID_IWMPPlaylistCollection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD newPlaylist <552> ( _                         ' VTable offset = 28
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppItem
   ' =====================================================================================
   METHOD getAll <553> ( _                              ' VTable offset = 32
   ) AS IWMPPlaylistArray                               ' __out_retval IWMPPlaylistArray **ppPlaylistArray
   ' =====================================================================================
   METHOD getByName <554> ( _                           ' VTable offset = 36
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IWMPPlaylistArray                               ' __out_retval IWMPPlaylistArray **ppPlaylistArray
   ' =====================================================================================
   METHOD remove <556> ( _                              ' VTable offset = 40
     BYVAL pItem AS IWMPPlaylist _                      ' __in IWMPPlaylist *pItem
   )                                                    ' void
   ' =====================================================================================
   METHOD setDeleted <560> ( _                          ' VTable offset = 44
     BYVAL pItem AS IWMPPlaylist _                      ' __in IWMPPlaylist *pItem
   , BYVAL varfIsDeleted AS INTEGER _                   ' __in VARIANT_BOOL varfIsDeleted
   )                                                    ' void
   ' =====================================================================================
   METHOD isDeleted <561> ( _                           ' VTable offset = 48
     BYVAL pItem AS IWMPPlaylist _                      ' __in IWMPPlaylist *pItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsDeleted
   ' =====================================================================================
   METHOD importPlaylist <562> ( _                      ' VTable offset = 52
     BYVAL pItem AS IWMPPlaylist _                      ' __in IWMPPlaylist *pItem
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppImportedItem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlaylistCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPNetwork
' IID = {EC21B779-EDEF-462D-BBA4-AD9DDE2B29A7}
' IWMPNetwork: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPNetwork_INTERFACE_DEFINED)
    %IWMPNetwork_INTERFACE_DEFINED = 1

INTERFACE IWMPNetwork $IID_IWMPNetwork

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET bandWidth <801> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plBandwidth
   ' =====================================================================================
   PROPERTY GET recoveredPackets <802> ( _              ' VTable offset = 32
   ) AS LONG                                            ' __out_retval long *plRecoveredPackets
   ' =====================================================================================
   PROPERTY GET sourceProtocol <803> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSourceProtocol
   ' =====================================================================================
   PROPERTY GET receivedPackets <804> ( _               ' VTable offset = 40
   ) AS LONG                                            ' __out_retval long *plReceivedPackets
   ' =====================================================================================
   PROPERTY GET lostPackets <805> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *plLostPackets
   ' =====================================================================================
   PROPERTY GET receptionQuality <806> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __out_retval long *plReceptionQuality
   ' =====================================================================================
   PROPERTY GET bufferingCount <807> ( _                ' VTable offset = 52
   ) AS LONG                                            ' __out_retval long *plBufferingCount
   ' =====================================================================================
   PROPERTY GET bufferingProgress <808> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __out_retval long *plBufferingProgress
   ' =====================================================================================
   PROPERTY GET bufferingTime <809> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __out_retval long *plBufferingTime
   ' =====================================================================================
   PROPERTY SET bufferingTime <809> ( _                 ' VTable offset = 64
     BYVAL plBufferingTime AS LONG _                    ' __in long plBufferingTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET frameRate <810> ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __out_retval long *plFrameRate
   ' =====================================================================================
   PROPERTY GET maxBitRate <811> ( _                    ' VTable offset = 72
   ) AS LONG                                            ' __out_retval long *plBitRate
   ' =====================================================================================
   PROPERTY GET bitRate <812> ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __out_retval long *plBitRate
   ' =====================================================================================
   METHOD getProxySettings <813> ( _                    ' VTable offset = 80
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   ) AS LONG                                            ' __out_retval long *plProxySetting
   ' =====================================================================================
   METHOD setProxySettings <814> ( _                    ' VTable offset = 84
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   , BYVAL lProxySetting AS LONG _                      ' __in long lProxySetting
   )                                                    ' void
   ' =====================================================================================
   METHOD getProxyName <815> ( _                        ' VTable offset = 88
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrProxyName
   ' =====================================================================================
   METHOD setProxyName <816> ( _                        ' VTable offset = 92
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   , BYVAL bstrProxyName AS WSTRING _                   ' __in BSTR bstrProxyName
   )                                                    ' void
   ' =====================================================================================
   METHOD getProxyPort <817> ( _                        ' VTable offset = 96
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   ) AS LONG                                            ' __out_retval long *lProxyPort
   ' =====================================================================================
   METHOD setProxyPort <818> ( _                        ' VTable offset = 100
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   , BYVAL lProxyPort AS LONG _                         ' __in long lProxyPort
   )                                                    ' void
   ' =====================================================================================
   METHOD getProxyExceptionList <819> ( _               ' VTable offset = 104
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrExceptionList
   ' =====================================================================================
   METHOD setProxyExceptionList <820> ( _               ' VTable offset = 108
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   , BYVAL pbstrExceptionList AS WSTRING _              ' __in BSTR pbstrExceptionList
   )                                                    ' void
   ' =====================================================================================
   METHOD getProxyBypassForLocal <821> ( _              ' VTable offset = 112
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfBypassForLocal
   ' =====================================================================================
   METHOD setProxyBypassForLocal <822> ( _              ' VTable offset = 116
     BYVAL bstrProtocol AS WSTRING _                    ' __in BSTR bstrProtocol
   , BYVAL fBypassForLocal AS INTEGER _                 ' __in VARIANT_BOOL fBypassForLocal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET maxBandwidth <823> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __out_retval long *lMaxBandwidth
   ' =====================================================================================
   PROPERTY SET maxBandwidth <823> ( _                  ' VTable offset = 124
     BYVAL lMaxBandwidth AS LONG _                      ' __in long lMaxBandwidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET downloadProgress <824> ( _              ' VTable offset = 128
   ) AS LONG                                            ' __out_retval long *plDownloadProgress
   ' =====================================================================================
   PROPERTY GET encodedFrameRate <825> ( _              ' VTable offset = 132
   ) AS LONG                                            ' __out_retval long *plFrameRate
   ' =====================================================================================
   PROPERTY GET framesSkipped <826> ( _                 ' VTable offset = 136
   ) AS LONG                                            ' __out_retval long *plFrames
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPNetwork_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPCore
' IID = {D84CCA99-CCE2-11D2-9ECC-0000F8085981}
' IWMPCore: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPCore_INTERFACE_DEFINED)
    %IWMPCore_INTERFACE_DEFINED = 1

INTERFACE IWMPCore $IID_IWMPCore

   INHERIT IDispatch

   ' =====================================================================================
   METHOD close <3> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <1> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <1> ( _                             ' VTable offset = 36
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET openState <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPOpenState *pwmpos
   ' =====================================================================================
   PROPERTY GET playState <10> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WMPPlayState *pwmpps
   ' =====================================================================================
   PROPERTY GET controls <4> ( _                        ' VTable offset = 48
   ) AS IWMPControls                                    ' __out_retval IWMPControls **ppControl
   ' =====================================================================================
   PROPERTY GET settings <5> ( _                        ' VTable offset = 52
   ) AS IWMPSettings                                    ' __out_retval IWMPSettings **ppSettings
   ' =====================================================================================
   PROPERTY GET currentMedia <6> ( _                    ' VTable offset = 56
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================
   PROPERTY SET currentMedia <6> ( _                    ' VTable offset = 60
     BYVAL ppMedia AS IWMPMedia _                       ' __in IWMPMedia *ppMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mediaCollection <8> ( _                 ' VTable offset = 64
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET playlistCollection <9> ( _              ' VTable offset = 68
   ) AS IWMPPlaylistCollection                          ' __out_retval IWMPPlaylistCollection **ppPlaylistCollection
   ' =====================================================================================
   PROPERTY GET versionInfo <11> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVersionInfo
   ' =====================================================================================
   METHOD launchURL <12> ( _                            ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET network <7> ( _                         ' VTable offset = 80
   ) AS IWMPNetwork                                     ' __out_retval IWMPNetwork **ppQNI
   ' =====================================================================================
   PROPERTY GET currentPlaylist <13> ( _                ' VTable offset = 84
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPL
   ' =====================================================================================
   PROPERTY SET currentPlaylist <13> ( _                ' VTable offset = 88
     BYVAL ppPL AS IWMPPlaylist _                       ' __in IWMPPlaylist *ppPL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cdromCollection <14> ( _                ' VTable offset = 92
   ) AS IWMPCdromCollection                             ' __out_retval IWMPCdromCollection **ppCdromCollection
   ' =====================================================================================
   PROPERTY GET closedCaption <15> ( _                  ' VTable offset = 96
   ) AS IWMPClosedCaption                               ' __out_retval IWMPClosedCaption **ppClosedCaption
   ' =====================================================================================
   PROPERTY GET isOnline <16> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfOnline
   ' =====================================================================================
   PROPERTY GET Error <17> ( _                          ' VTable offset = 104
   ) AS IWMPError                                       ' __out_retval IWMPError **ppError
   ' =====================================================================================
   PROPERTY GET status <18> ( _                         ' VTable offset = 108
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrStatus
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPCore_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlayer
' IID = {6BF52A4F-394A-11D3-B153-00C04F79FAA6}
' IWMPPlayer: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPCore
' ########################################################################################

#IF NOT %DEF(%IWMPPlayer_INTERFACE_DEFINED)
    %IWMPPlayer_INTERFACE_DEFINED = 1

INTERFACE IWMPPlayer $IID_IWMPPlayer

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPCore Methods
   ' =====================================================================================
   METHOD close <3> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <1> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <1> ( _                             ' VTable offset = 36
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET openState <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPOpenState *pwmpos
   ' =====================================================================================
   PROPERTY GET playState <10> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WMPPlayState *pwmpps
   ' =====================================================================================
   PROPERTY GET controls <4> ( _                        ' VTable offset = 48
   ) AS IWMPControls                                    ' __out_retval IWMPControls **ppControl
   ' =====================================================================================
   PROPERTY GET settings <5> ( _                        ' VTable offset = 52
   ) AS IWMPSettings                                    ' __out_retval IWMPSettings **ppSettings
   ' =====================================================================================
   PROPERTY GET currentMedia <6> ( _                    ' VTable offset = 56
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================
   PROPERTY SET currentMedia <6> ( _                    ' VTable offset = 60
     BYVAL ppMedia AS IWMPMedia _                       ' __in IWMPMedia *ppMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mediaCollection <8> ( _                 ' VTable offset = 64
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET playlistCollection <9> ( _              ' VTable offset = 68
   ) AS IWMPPlaylistCollection                          ' __out_retval IWMPPlaylistCollection **ppPlaylistCollection
   ' =====================================================================================
   PROPERTY GET versionInfo <11> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVersionInfo
   ' =====================================================================================
   METHOD launchURL <12> ( _                            ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET network <7> ( _                         ' VTable offset = 80
   ) AS IWMPNetwork                                     ' __out_retval IWMPNetwork **ppQNI
   ' =====================================================================================
   PROPERTY GET currentPlaylist <13> ( _                ' VTable offset = 84
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPL
   ' =====================================================================================
   PROPERTY SET currentPlaylist <13> ( _                ' VTable offset = 88
     BYVAL ppPL AS IWMPPlaylist _                       ' __in IWMPPlaylist *ppPL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cdromCollection <14> ( _                ' VTable offset = 92
   ) AS IWMPCdromCollection                             ' __out_retval IWMPCdromCollection **ppCdromCollection
   ' =====================================================================================
   PROPERTY GET closedCaption <15> ( _                  ' VTable offset = 96
   ) AS IWMPClosedCaption                               ' __out_retval IWMPClosedCaption **ppClosedCaption
   ' =====================================================================================
   PROPERTY GET isOnline <16> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfOnline
   ' =====================================================================================
   PROPERTY GET Error <17> ( _                          ' VTable offset = 104
   ) AS IWMPError                                       ' __out_retval IWMPError **ppError
   ' =====================================================================================
   PROPERTY GET status <18> ( _                         ' VTable offset = 108
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrStatus
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPPlayer Methods
   ' =====================================================================================
   PROPERTY GET enabled <19> ( _                        ' VTable offset = 112
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET enabled <19> ( _                        ' VTable offset = 116
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fullScreen <21> ( _                     ' VTable offset = 120
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbFullScreen
   ' =====================================================================================
   PROPERTY SET fullScreen <21> ( _                     ' VTable offset = 124
     BYVAL pbFullScreen AS INTEGER _                    ' __in VARIANT_BOOL pbFullScreen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET enableContextMenu <22> ( _              ' VTable offset = 128
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnableContextMenu
   ' =====================================================================================
   PROPERTY SET enableContextMenu <22> ( _              ' VTable offset = 132
     BYVAL pbEnableContextMenu AS INTEGER _             ' __in VARIANT_BOOL pbEnableContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET uiMode <23> ( _                         ' VTable offset = 136
     BYVAL pbstrMode AS WSTRING _                       ' __in BSTR pbstrMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET uiMode <23> ( _                         ' VTable offset = 140
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlayer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlayer2
' IID = {0E6B01D1-D407-4C85-BF5F-1C01F6150280}
' IWMPPlayer2: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPCore
' ########################################################################################

#IF NOT %DEF(%IWMPPlayer2_INTERFACE_DEFINED)
    %IWMPPlayer2_INTERFACE_DEFINED = 1

INTERFACE IWMPPlayer2 $IID_IWMPPlayer2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPCore Methods
   ' =====================================================================================
   METHOD close <3> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <1> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <1> ( _                             ' VTable offset = 36
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET openState <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPOpenState *pwmpos
   ' =====================================================================================
   PROPERTY GET playState <10> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WMPPlayState *pwmpps
   ' =====================================================================================
   PROPERTY GET controls <4> ( _                        ' VTable offset = 48
   ) AS IWMPControls                                    ' __out_retval IWMPControls **ppControl
   ' =====================================================================================
   PROPERTY GET settings <5> ( _                        ' VTable offset = 52
   ) AS IWMPSettings                                    ' __out_retval IWMPSettings **ppSettings
   ' =====================================================================================
   PROPERTY GET currentMedia <6> ( _                    ' VTable offset = 56
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================
   PROPERTY SET currentMedia <6> ( _                    ' VTable offset = 60
     BYVAL ppMedia AS IWMPMedia _                       ' __in IWMPMedia *ppMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mediaCollection <8> ( _                 ' VTable offset = 64
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET playlistCollection <9> ( _              ' VTable offset = 68
   ) AS IWMPPlaylistCollection                          ' __out_retval IWMPPlaylistCollection **ppPlaylistCollection
   ' =====================================================================================
   PROPERTY GET versionInfo <11> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVersionInfo
   ' =====================================================================================
   METHOD launchURL <12> ( _                            ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET network <7> ( _                         ' VTable offset = 80
   ) AS IWMPNetwork                                     ' __out_retval IWMPNetwork **ppQNI
   ' =====================================================================================
   PROPERTY GET currentPlaylist <13> ( _                ' VTable offset = 84
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPL
   ' =====================================================================================
   PROPERTY SET currentPlaylist <13> ( _                ' VTable offset = 88
     BYVAL ppPL AS IWMPPlaylist _                       ' __in IWMPPlaylist *ppPL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cdromCollection <14> ( _                ' VTable offset = 92
   ) AS IWMPCdromCollection                             ' __out_retval IWMPCdromCollection **ppCdromCollection
   ' =====================================================================================
   PROPERTY GET closedCaption <15> ( _                  ' VTable offset = 96
   ) AS IWMPClosedCaption                               ' __out_retval IWMPClosedCaption **ppClosedCaption
   ' =====================================================================================
   PROPERTY GET isOnline <16> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfOnline
   ' =====================================================================================
   PROPERTY GET Error <17> ( _                          ' VTable offset = 104
   ) AS IWMPError                                       ' __out_retval IWMPError **ppError
   ' =====================================================================================
   PROPERTY GET status <18> ( _                         ' VTable offset = 108
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrStatus
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPPlayer2 Methods
   ' =====================================================================================
   PROPERTY GET enabled <19> ( _                        ' VTable offset = 112
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET enabled <19> ( _                        ' VTable offset = 116
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fullScreen <21> ( _                     ' VTable offset = 120
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbFullScreen
   ' =====================================================================================
   PROPERTY SET fullScreen <21> ( _                     ' VTable offset = 124
     BYVAL pbFullScreen AS INTEGER _                    ' __in VARIANT_BOOL pbFullScreen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET enableContextMenu <22> ( _              ' VTable offset = 128
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnableContextMenu
   ' =====================================================================================
   PROPERTY SET enableContextMenu <22> ( _              ' VTable offset = 132
     BYVAL pbEnableContextMenu AS INTEGER _             ' __in VARIANT_BOOL pbEnableContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET uiMode <23> ( _                         ' VTable offset = 136
     BYVAL pbstrMode AS WSTRING _                       ' __in BSTR pbstrMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET uiMode <23> ( _                         ' VTable offset = 140
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMode
   ' =====================================================================================
   PROPERTY GET stretchToFit <24> ( _                   ' VTable offset = 144
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET stretchToFit <24> ( _                   ' VTable offset = 148
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET windowlessVideo <25> ( _                ' VTable offset = 152
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET windowlessVideo <25> ( _                ' VTable offset = 156
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlayer2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPMedia2
' IID = {AB7C88BB-143E-4EA4-ACC3-E4350B2106C3}
' IWMPMedia2: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPMedia
' ########################################################################################

#IF NOT %DEF(%IWMPMedia2_INTERFACE_DEFINED)
    %IWMPMedia2_INTERFACE_DEFINED = 1

INTERFACE IWMPMedia2 $IID_IWMPMedia2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPMedia Methods
   ' =====================================================================================
   PROPERTY GET isIdentical <763> ( _                   ' VTable offset = 28
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================
   PROPERTY GET sourceURL <751> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSourceURL
   ' =====================================================================================
   PROPERTY GET name <764> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET name <764> ( _                          ' VTable offset = 40
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET imageSourceWidth <752> ( _              ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *pWidth
   ' =====================================================================================
   PROPERTY GET imageSourceHeight <753> ( _             ' VTable offset = 48
   ) AS LONG                                            ' __out_retval long *pHeight
   ' =====================================================================================
   PROPERTY GET markerCount <754> ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __out_retval long *pMarkerCount
   ' =====================================================================================
   METHOD getMarkerTime <755> ( _                       ' VTable offset = 56
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS DOUBLE                                          ' __out_retval double *pMarkerTime
   ' =====================================================================================
   METHOD getMarkerName <756> ( _                       ' VTable offset = 60
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMarkerName
   ' =====================================================================================
   PROPERTY GET duration <757> ( _                      ' VTable offset = 64
   ) AS DOUBLE                                          ' __out_retval double *pDuration
   ' =====================================================================================
   PROPERTY GET durationString <758> ( _                ' VTable offset = 68
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDuration
   ' =====================================================================================
   PROPERTY GET attributeCount <759> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getAttributeName <760> ( _                    ' VTable offset = 76
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrItemName
   ' =====================================================================================
   METHOD getItemInfo <761> ( _                         ' VTable offset = 80
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD setItemInfo <762> ( _                         ' VTable offset = 84
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   METHOD getItemInfoByAtom <765> ( _                   ' VTable offset = 88
     BYVAL lAtom AS LONG _                              ' __in long lAtom
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD isMemberOf <766> ( _                          ' VTable offset = 92
     BYVAL pPlaylist AS IWMPPlaylist _                  ' __in IWMPPlaylist *pPlaylist
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsMemberOf
   ' =====================================================================================
   METHOD isReadOnlyItem <767> ( _                      ' VTable offset = 96
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsReadOnly
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPMedia2 Methods
   ' =====================================================================================
   PROPERTY GET Error <768> ( _                         ' VTable offset = 100
   ) AS IWMPErrorItem                                   ' __out_retval IWMPErrorItem **ppIWMPErrorItem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPMedia2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPControls2
' IID = {6F030D25-0890-480F-9775-1F7E40AB5B8E}
' IWMPControls2: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPControls
' ########################################################################################

#IF NOT %DEF(%IWMPControls2_INTERFACE_DEFINED)
    %IWMPControls2_INTERFACE_DEFINED = 1

INTERFACE IWMPControls2 $IID_IWMPControls2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPControls Methods
   ' =====================================================================================
   PROPERTY GET isAvailable <62> ( _                    ' VTable offset = 28
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pIsAvailable
   ' =====================================================================================
   METHOD play <51> ( _                                 ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD stop <52> ( _                                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD pause <53> ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD fastForward <54> ( _                          ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD fastReverse <55> ( _                          ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPosition <56> ( _                ' VTable offset = 52
   ) AS DOUBLE                                          ' __out_retval double *pdCurrentPosition
   ' =====================================================================================
   PROPERTY SET currentPosition <56> ( _                ' VTable offset = 56
     BYVAL pdCurrentPosition AS DOUBLE _                ' __in double pdCurrentPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPositionString <57> ( _          ' VTable offset = 60
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrCurrentPosition
   ' =====================================================================================
   METHOD next <58> ( _                                 ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD previous <59> ( _                             ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentItem <60> ( _                    ' VTable offset = 72
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppIWMPMedia
   ' =====================================================================================
   PROPERTY SET currentItem <60> ( _                    ' VTable offset = 76
     BYVAL ppIWMPMedia AS IWMPMedia _                   ' __in IWMPMedia *ppIWMPMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentMarker <61> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __out_retval long *plMarker
   ' =====================================================================================
   PROPERTY SET currentMarker <61> ( _                  ' VTable offset = 84
     BYVAL plMarker AS LONG _                           ' __in long plMarker
   )                                                    ' void
   ' =====================================================================================
   METHOD playItem <63> ( _                             ' VTable offset = 88
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPControls2 Methods
   ' =====================================================================================
   METHOD step <64> ( _                                 ' VTable offset = 92
     BYVAL lStep AS LONG _                              ' __in long lStep
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPControls2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPDVD
' IID = {8DA61686-4668-4A5C-AE5D-803193293DBE}
' IWMPDVD: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPDVD_INTERFACE_DEFINED)
    %IWMPDVD_INTERFACE_DEFINED = 1

INTERFACE IWMPDVD $IID_IWMPDVD

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET isAvailable <1001> ( _                  ' VTable offset = 28
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pIsAvailable
   ' =====================================================================================
   PROPERTY GET domain <1002> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *strDomain
   ' =====================================================================================
   METHOD topMenu <1003> ( _                            ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD titleMenu <1004> ( _                          ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD back <1005> ( _                               ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD resume <1006> ( _                             ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPDVD_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPCore2
' IID = {BC17E5B7-7561-4C18-BB90-17D485775659}
' IWMPCore2: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPCore
' ########################################################################################

#IF NOT %DEF(%IWMPCore2_INTERFACE_DEFINED)
    %IWMPCore2_INTERFACE_DEFINED = 1

INTERFACE IWMPCore2 $IID_IWMPCore2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPCore Methods
   ' =====================================================================================
   METHOD close <3> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <1> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <1> ( _                             ' VTable offset = 36
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET openState <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPOpenState *pwmpos
   ' =====================================================================================
   PROPERTY GET playState <10> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WMPPlayState *pwmpps
   ' =====================================================================================
   PROPERTY GET controls <4> ( _                        ' VTable offset = 48
   ) AS IWMPControls                                    ' __out_retval IWMPControls **ppControl
   ' =====================================================================================
   PROPERTY GET settings <5> ( _                        ' VTable offset = 52
   ) AS IWMPSettings                                    ' __out_retval IWMPSettings **ppSettings
   ' =====================================================================================
   PROPERTY GET currentMedia <6> ( _                    ' VTable offset = 56
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================
   PROPERTY SET currentMedia <6> ( _                    ' VTable offset = 60
     BYVAL ppMedia AS IWMPMedia _                       ' __in IWMPMedia *ppMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mediaCollection <8> ( _                 ' VTable offset = 64
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET playlistCollection <9> ( _              ' VTable offset = 68
   ) AS IWMPPlaylistCollection                          ' __out_retval IWMPPlaylistCollection **ppPlaylistCollection
   ' =====================================================================================
   PROPERTY GET versionInfo <11> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVersionInfo
   ' =====================================================================================
   METHOD launchURL <12> ( _                            ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET network <7> ( _                         ' VTable offset = 80
   ) AS IWMPNetwork                                     ' __out_retval IWMPNetwork **ppQNI
   ' =====================================================================================
   PROPERTY GET currentPlaylist <13> ( _                ' VTable offset = 84
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPL
   ' =====================================================================================
   PROPERTY SET currentPlaylist <13> ( _                ' VTable offset = 88
     BYVAL ppPL AS IWMPPlaylist _                       ' __in IWMPPlaylist *ppPL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cdromCollection <14> ( _                ' VTable offset = 92
   ) AS IWMPCdromCollection                             ' __out_retval IWMPCdromCollection **ppCdromCollection
   ' =====================================================================================
   PROPERTY GET closedCaption <15> ( _                  ' VTable offset = 96
   ) AS IWMPClosedCaption                               ' __out_retval IWMPClosedCaption **ppClosedCaption
   ' =====================================================================================
   PROPERTY GET isOnline <16> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfOnline
   ' =====================================================================================
   PROPERTY GET Error <17> ( _                          ' VTable offset = 104
   ) AS IWMPError                                       ' __out_retval IWMPError **ppError
   ' =====================================================================================
   PROPERTY GET status <18> ( _                         ' VTable offset = 108
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrStatus
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPCore2 Methods
   ' =====================================================================================
   PROPERTY GET dvd <40> ( _                            ' VTable offset = 112
   ) AS IWMPDVD                                         ' __out_retval IWMPDVD **ppDVD
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPCore2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlayer3
' IID = {54062B68-052A-4C25-A39F-8B63346511D4}
' IWMPPlayer3: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPCore2
' ########################################################################################

#IF NOT %DEF(%IWMPPlayer3_INTERFACE_DEFINED)
    %IWMPPlayer3_INTERFACE_DEFINED = 1

INTERFACE IWMPPlayer3 $IID_IWMPPlayer3

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPCore Methods
   ' =====================================================================================
   METHOD close <3> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <1> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <1> ( _                             ' VTable offset = 36
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET openState <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPOpenState *pwmpos
   ' =====================================================================================
   PROPERTY GET playState <10> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WMPPlayState *pwmpps
   ' =====================================================================================
   PROPERTY GET controls <4> ( _                        ' VTable offset = 48
   ) AS IWMPControls                                    ' __out_retval IWMPControls **ppControl
   ' =====================================================================================
   PROPERTY GET settings <5> ( _                        ' VTable offset = 52
   ) AS IWMPSettings                                    ' __out_retval IWMPSettings **ppSettings
   ' =====================================================================================
   PROPERTY GET currentMedia <6> ( _                    ' VTable offset = 56
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================
   PROPERTY SET currentMedia <6> ( _                    ' VTable offset = 60
     BYVAL ppMedia AS IWMPMedia _                       ' __in IWMPMedia *ppMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mediaCollection <8> ( _                 ' VTable offset = 64
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET playlistCollection <9> ( _              ' VTable offset = 68
   ) AS IWMPPlaylistCollection                          ' __out_retval IWMPPlaylistCollection **ppPlaylistCollection
   ' =====================================================================================
   PROPERTY GET versionInfo <11> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVersionInfo
   ' =====================================================================================
   METHOD launchURL <12> ( _                            ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET network <7> ( _                         ' VTable offset = 80
   ) AS IWMPNetwork                                     ' __out_retval IWMPNetwork **ppQNI
   ' =====================================================================================
   PROPERTY GET currentPlaylist <13> ( _                ' VTable offset = 84
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPL
   ' =====================================================================================
   PROPERTY SET currentPlaylist <13> ( _                ' VTable offset = 88
     BYVAL ppPL AS IWMPPlaylist _                       ' __in IWMPPlaylist *ppPL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cdromCollection <14> ( _                ' VTable offset = 92
   ) AS IWMPCdromCollection                             ' __out_retval IWMPCdromCollection **ppCdromCollection
   ' =====================================================================================
   PROPERTY GET closedCaption <15> ( _                  ' VTable offset = 96
   ) AS IWMPClosedCaption                               ' __out_retval IWMPClosedCaption **ppClosedCaption
   ' =====================================================================================
   PROPERTY GET isOnline <16> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfOnline
   ' =====================================================================================
   PROPERTY GET Error <17> ( _                          ' VTable offset = 104
   ) AS IWMPError                                       ' __out_retval IWMPError **ppError
   ' =====================================================================================
   PROPERTY GET status <18> ( _                         ' VTable offset = 108
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrStatus
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPCore2 Methods
   ' =====================================================================================
   PROPERTY GET dvd <40> ( _                            ' VTable offset = 112
   ) AS IWMPDVD                                         ' __out_retval IWMPDVD **ppDVD
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPPlayer3 Methods
   ' =====================================================================================
   PROPERTY GET enabled <19> ( _                        ' VTable offset = 116
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET enabled <19> ( _                        ' VTable offset = 120
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fullScreen <21> ( _                     ' VTable offset = 124
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbFullScreen
   ' =====================================================================================
   PROPERTY SET fullScreen <21> ( _                     ' VTable offset = 128
     BYVAL pbFullScreen AS INTEGER _                    ' __in VARIANT_BOOL pbFullScreen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET enableContextMenu <22> ( _              ' VTable offset = 132
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnableContextMenu
   ' =====================================================================================
   PROPERTY SET enableContextMenu <22> ( _              ' VTable offset = 136
     BYVAL pbEnableContextMenu AS INTEGER _             ' __in VARIANT_BOOL pbEnableContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET uiMode <23> ( _                         ' VTable offset = 140
     BYVAL pbstrMode AS WSTRING _                       ' __in BSTR pbstrMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET uiMode <23> ( _                         ' VTable offset = 144
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMode
   ' =====================================================================================
   PROPERTY GET stretchToFit <24> ( _                   ' VTable offset = 148
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET stretchToFit <24> ( _                   ' VTable offset = 152
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET windowlessVideo <25> ( _                ' VTable offset = 156
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET windowlessVideo <25> ( _                ' VTable offset = 160
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlayer3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPErrorItem2
' IID = {F75CCEC0-C67C-475C-931E-8719870BEE7D}
' IWMPErrorItem2: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPErrorItem
' ########################################################################################

#IF NOT %DEF(%IWMPErrorItem2_INTERFACE_DEFINED)
    %IWMPErrorItem2_INTERFACE_DEFINED = 1

INTERFACE IWMPErrorItem2 $IID_IWMPErrorItem2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPErrorItem Methods
   ' =====================================================================================
   PROPERTY GET errorCode <901> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *phr
   ' =====================================================================================
   PROPERTY GET errorDescription <902> ( _              ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY GET errorContext <903> ( _                  ' VTable offset = 36
   ) AS VARIANT                                         ' __out_retval VARIANT *pvarContext
   ' =====================================================================================
   PROPERTY GET remedy <904> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __out_retval long *plRemedy
   ' =====================================================================================
   PROPERTY GET customUrl <905> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrCustomUrl
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPErrorItem2 Methods
   ' =====================================================================================
   PROPERTY GET condition <906> ( _                     ' VTable offset = 48
   ) AS LONG                                            ' __out_retval long *plCondition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPErrorItem2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPRemoteMediaServices
' IID = {CBB92747-741F-44FE-AB5B-F1A48F3B2A59}
' IWMPRemoteMediaServices: Public interface for Windows Media Player SDK.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPRemoteMediaServices_INTERFACE_DEFINED)
    %IWMPRemoteMediaServices_INTERFACE_DEFINED = 1

INTERFACE IWMPRemoteMediaServices $IID_IWMPRemoteMediaServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetServiceType ( _                            ' VTable offset = 12
     BYREF pbstrType AS WSTRING _                       ' __out BSTR *pbstrType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplicationName ( _                        ' VTable offset = 16
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptableObject ( _                       ' VTable offset = 20
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   , BYREF ppDispatch AS IDispatch _                    ' __out IDispatch **ppDispatch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustomUIMode ( _                           ' VTable offset = 24
     BYREF pbstrFile AS WSTRING _                       ' __out BSTR *pbstrFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPRemoteMediaServices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPSkinManager
' IID = {076F2FA6-ED30-448B-8CC5-3F3EF3529C7A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPSkinManager_INTERFACE_DEFINED)
    %IWMPSkinManager_INTERFACE_DEFINED = 1

INTERFACE IWMPSkinManager $IID_IWMPSkinManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetVisualStyle ( _                            ' VTable offset = 12
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPSkinManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPMetadataPicture
' IID = {5C29BBE0-F87D-4C45-AA28-A70F0230FFA9}
' IWMPMetadataPicture: Not Public.  Internal interface used by Windows Media Player.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPMetadataPicture_INTERFACE_DEFINED)
    %IWMPMetadataPicture_INTERFACE_DEFINED = 1

INTERFACE IWMPMetadataPicture $IID_IWMPMetadataPicture

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET mimeType <1051> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMimeType
   ' =====================================================================================
   PROPERTY GET pictureType <1052> ( _                  ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrPictureType
   ' =====================================================================================
   PROPERTY GET Description <1053> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY GET URL <1054> ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPMetadataPicture_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPMetadataText
' IID = {769A72DB-13D2-45E2-9C48-53CA9D5B7450}
' IWMPMetadataText: Not Public.  Internal interface used by Windows Media Player.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPMetadataText_INTERFACE_DEFINED)
    %IWMPMetadataText_INTERFACE_DEFINED = 1

INTERFACE IWMPMetadataText $IID_IWMPMetadataText

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Description <1056> ( _                  ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY GET text <1055> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPMetadataText_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPMedia3
' IID = {F118EFC7-F03A-4FB4-99C9-1C02A5C1065B}
' IWMPMedia3: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPMedia2
' ########################################################################################

#IF NOT %DEF(%IWMPMedia3_INTERFACE_DEFINED)
    %IWMPMedia3_INTERFACE_DEFINED = 1

INTERFACE IWMPMedia3 $IID_IWMPMedia3

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPMedia Methods
   ' =====================================================================================
   PROPERTY GET isIdentical <763> ( _                   ' VTable offset = 28
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================
   PROPERTY GET sourceURL <751> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSourceURL
   ' =====================================================================================
   PROPERTY GET name <764> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET name <764> ( _                          ' VTable offset = 40
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET imageSourceWidth <752> ( _              ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *pWidth
   ' =====================================================================================
   PROPERTY GET imageSourceHeight <753> ( _             ' VTable offset = 48
   ) AS LONG                                            ' __out_retval long *pHeight
   ' =====================================================================================
   PROPERTY GET markerCount <754> ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __out_retval long *pMarkerCount
   ' =====================================================================================
   METHOD getMarkerTime <755> ( _                       ' VTable offset = 56
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS DOUBLE                                          ' __out_retval double *pMarkerTime
   ' =====================================================================================
   METHOD getMarkerName <756> ( _                       ' VTable offset = 60
     BYVAL MarkerNum AS LONG _                          ' __in long MarkerNum
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMarkerName
   ' =====================================================================================
   PROPERTY GET duration <757> ( _                      ' VTable offset = 64
   ) AS DOUBLE                                          ' __out_retval double *pDuration
   ' =====================================================================================
   PROPERTY GET durationString <758> ( _                ' VTable offset = 68
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDuration
   ' =====================================================================================
   PROPERTY GET attributeCount <759> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getAttributeName <760> ( _                    ' VTable offset = 76
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrItemName
   ' =====================================================================================
   METHOD getItemInfo <761> ( _                         ' VTable offset = 80
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD setItemInfo <762> ( _                         ' VTable offset = 84
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   METHOD getItemInfoByAtom <765> ( _                   ' VTable offset = 88
     BYVAL lAtom AS LONG _                              ' __in long lAtom
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD isMemberOf <766> ( _                          ' VTable offset = 92
     BYVAL pPlaylist AS IWMPPlaylist _                  ' __in IWMPPlaylist *pPlaylist
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsMemberOf
   ' =====================================================================================
   METHOD isReadOnlyItem <767> ( _                      ' VTable offset = 96
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsReadOnly
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPMedia2 Methods
   ' =====================================================================================
   PROPERTY GET Error <768> ( _                         ' VTable offset = 100
   ) AS IWMPErrorItem                                   ' __out_retval IWMPErrorItem **ppIWMPErrorItem
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPMedia3 Methods
   ' =====================================================================================
   METHOD getAttributeCountByType <769> ( _             ' VTable offset = 104
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getItemInfoByType <770> ( _                   ' VTable offset = 108
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __out_retval VARIANT *pvarValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPMedia3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPSettings2
' IID = {FDA937A4-EECE-4DA5-A0B6-39BF89ADE2C2}
' IWMPSettings2: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPSettings
' ########################################################################################

#IF NOT %DEF(%IWMPSettings2_INTERFACE_DEFINED)
    %IWMPSettings2_INTERFACE_DEFINED = 1

INTERFACE IWMPSettings2 $IID_IWMPSettings2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPSettings Methods
   ' =====================================================================================
   PROPERTY GET isAvailable <113> ( _                   ' VTable offset = 28
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pIsAvailable
   ' =====================================================================================
   PROPERTY GET autoStart <101> ( _                     ' VTable offset = 32
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfAutoStart
   ' =====================================================================================
   PROPERTY SET autoStart <101> ( _                     ' VTable offset = 36
     BYVAL pfAutoStart AS INTEGER _                     ' __in VARIANT_BOOL pfAutoStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET baseURL <108> ( _                       ' VTable offset = 40
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrBaseURL
   ' =====================================================================================
   PROPERTY SET baseURL <108> ( _                       ' VTable offset = 44
     BYVAL pbstrBaseURL AS WSTRING _                    ' __in BSTR pbstrBaseURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET defaultFrame <109> ( _                  ' VTable offset = 48
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDefaultFrame
   ' =====================================================================================
   PROPERTY SET defaultFrame <109> ( _                  ' VTable offset = 52
     BYVAL pbstrDefaultFrame AS WSTRING _               ' __in BSTR pbstrDefaultFrame
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET invokeURLs <103> ( _                    ' VTable offset = 56
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfInvokeURLs
   ' =====================================================================================
   PROPERTY SET invokeURLs <103> ( _                    ' VTable offset = 60
     BYVAL pfInvokeURLs AS INTEGER _                    ' __in VARIANT_BOOL pfInvokeURLs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mute <104> ( _                          ' VTable offset = 64
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfMute
   ' =====================================================================================
   PROPERTY SET mute <104> ( _                          ' VTable offset = 68
     BYVAL pfMute AS INTEGER _                          ' __in VARIANT_BOOL pfMute
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET playCount <105> ( _                     ' VTable offset = 72
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   PROPERTY SET playCount <105> ( _                     ' VTable offset = 76
     BYVAL plCount AS LONG _                            ' __in long plCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET rate <106> ( _                          ' VTable offset = 80
   ) AS DOUBLE                                          ' __out_retval double *pdRate
   ' =====================================================================================
   PROPERTY SET rate <106> ( _                          ' VTable offset = 84
     BYVAL pdRate AS DOUBLE _                           ' __in double pdRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET balance <102> ( _                       ' VTable offset = 88
   ) AS LONG                                            ' __out_retval long *plBalance
   ' =====================================================================================
   PROPERTY SET balance <102> ( _                       ' VTable offset = 92
     BYVAL plBalance AS LONG _                          ' __in long plBalance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET volume <107> ( _                        ' VTable offset = 96
   ) AS LONG                                            ' __out_retval long *plVolume
   ' =====================================================================================
   PROPERTY SET volume <107> ( _                        ' VTable offset = 100
     BYVAL plVolume AS LONG _                           ' __in long plVolume
   )                                                    ' void
   ' =====================================================================================
   METHOD getMode <110> ( _                             ' VTable offset = 104
     BYVAL bstrMode AS WSTRING _                        ' __in BSTR bstrMode
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfMode
   ' =====================================================================================
   METHOD setMode <111> ( _                             ' VTable offset = 108
     BYVAL bstrMode AS WSTRING _                        ' __in BSTR bstrMode
   , BYVAL varfMode AS INTEGER _                        ' __in VARIANT_BOOL varfMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET enableErrorDialogs <112> ( _            ' VTable offset = 112
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfEnableErrorDialogs
   ' =====================================================================================
   PROPERTY SET enableErrorDialogs <112> ( _            ' VTable offset = 116
     BYVAL pfEnableErrorDialogs AS INTEGER _            ' __in VARIANT_BOOL pfEnableErrorDialogs
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPSettings2 Methods
   ' =====================================================================================
   PROPERTY GET defaultAudioLanguage <114> ( _          ' VTable offset = 120
   ) AS LONG                                            ' __out_retval long *plLangID
   ' =====================================================================================
   PROPERTY GET mediaAccessRights <115> ( _             ' VTable offset = 124
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrRights
   ' =====================================================================================
   METHOD requestMediaAccessRights <116> ( _            ' VTable offset = 128
     BYVAL bstrDesiredAccess AS WSTRING _               ' __in BSTR bstrDesiredAccess
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbAccepted
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPSettings2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPControls3
' IID = {A1D1110E-D545-476A-9A78-AC3E4CB1E6BD}
' IWMPControls3: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPControls2
' ########################################################################################

#IF NOT %DEF(%IWMPControls3_INTERFACE_DEFINED)
    %IWMPControls3_INTERFACE_DEFINED = 1

INTERFACE IWMPControls3 $IID_IWMPControls3

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPControls Methods
   ' =====================================================================================
   PROPERTY GET isAvailable <62> ( _                    ' VTable offset = 28
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pIsAvailable
   ' =====================================================================================
   METHOD play <51> ( _                                 ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD stop <52> ( _                                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD pause <53> ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD fastForward <54> ( _                          ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD fastReverse <55> ( _                          ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPosition <56> ( _                ' VTable offset = 52
   ) AS DOUBLE                                          ' __out_retval double *pdCurrentPosition
   ' =====================================================================================
   PROPERTY SET currentPosition <56> ( _                ' VTable offset = 56
     BYVAL pdCurrentPosition AS DOUBLE _                ' __in double pdCurrentPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentPositionString <57> ( _          ' VTable offset = 60
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrCurrentPosition
   ' =====================================================================================
   METHOD next <58> ( _                                 ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD previous <59> ( _                             ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentItem <60> ( _                    ' VTable offset = 72
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppIWMPMedia
   ' =====================================================================================
   PROPERTY SET currentItem <60> ( _                    ' VTable offset = 76
     BYVAL ppIWMPMedia AS IWMPMedia _                   ' __in IWMPMedia *ppIWMPMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentMarker <61> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __out_retval long *plMarker
   ' =====================================================================================
   PROPERTY SET currentMarker <61> ( _                  ' VTable offset = 84
     BYVAL plMarker AS LONG _                           ' __in long plMarker
   )                                                    ' void
   ' =====================================================================================
   METHOD playItem <63> ( _                             ' VTable offset = 88
     BYVAL pIWMPMedia AS IWMPMedia _                    ' __in IWMPMedia *pIWMPMedia
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPControls2 Methods
   ' =====================================================================================
   METHOD step <64> ( _                                 ' VTable offset = 92
     BYVAL lStep AS LONG _                              ' __in long lStep
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPControls3 Methods
   ' =====================================================================================
   PROPERTY GET audioLanguageCount <65> ( _             ' VTable offset = 96
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getAudioLanguageID <66> ( _                   ' VTable offset = 100
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS LONG                                            ' __out_retval long *plLangID
   ' =====================================================================================
   METHOD getAudioLanguageDescription <67> ( _          ' VTable offset = 104
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrLangDesc
   ' =====================================================================================
   PROPERTY GET currentAudioLanguage <68> ( _           ' VTable offset = 108
   ) AS LONG                                            ' __out_retval long *plLangID
   ' =====================================================================================
   PROPERTY SET currentAudioLanguage <68> ( _           ' VTable offset = 112
     BYVAL plLangID AS LONG _                           ' __in long plLangID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET currentAudioLanguageIndex <69> ( _      ' VTable offset = 116
   ) AS LONG                                            ' __out_retval long *plIndex
   ' =====================================================================================
   PROPERTY SET currentAudioLanguageIndex <69> ( _      ' VTable offset = 120
     BYVAL plIndex AS LONG _                            ' __in long plIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD getLanguageName <70> ( _                      ' VTable offset = 124
     BYVAL lLangID AS LONG _                            ' __in long lLangID
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrLangName
   ' =====================================================================================
   PROPERTY GET currentPositionTimecode <71> ( _        ' VTable offset = 128
   ) AS WSTRING                                         ' __out_retval BSTR *bstrTimecode
   ' =====================================================================================
   PROPERTY SET currentPositionTimecode <71> ( _        ' VTable offset = 132
     BYVAL bstrTimecode AS WSTRING _                    ' __in BSTR bstrTimecode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPControls3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPClosedCaption2
' IID = {350BA78B-6BC8-4113-A5F5-312056934EB6}
' IWMPClosedCaption2: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPClosedCaption
' ########################################################################################

#IF NOT %DEF(%IWMPClosedCaption2_INTERFACE_DEFINED)
    %IWMPClosedCaption2_INTERFACE_DEFINED = 1

INTERFACE IWMPClosedCaption2 $IID_IWMPClosedCaption2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPClosedCaption Methods
   ' =====================================================================================
   PROPERTY GET SAMIStyle <951> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSAMIStyle
   ' =====================================================================================
   PROPERTY SET SAMIStyle <951> ( _                     ' VTable offset = 32
     BYVAL pbstrSAMIStyle AS WSTRING _                  ' __in BSTR pbstrSAMIStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SAMILang <952> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSAMILang
   ' =====================================================================================
   PROPERTY SET SAMILang <952> ( _                      ' VTable offset = 40
     BYVAL pbstrSAMILang AS WSTRING _                   ' __in BSTR pbstrSAMILang
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SAMIFileName <953> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrSAMIFileName
   ' =====================================================================================
   PROPERTY SET SAMIFileName <953> ( _                  ' VTable offset = 48
     BYVAL pbstrSAMIFileName AS WSTRING _               ' __in BSTR pbstrSAMIFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET captioningId <954> ( _                  ' VTable offset = 52
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrCaptioningID
   ' =====================================================================================
   PROPERTY SET captioningId <954> ( _                  ' VTable offset = 56
     BYVAL pbstrCaptioningID AS WSTRING _               ' __in BSTR pbstrCaptioningID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPClosedCaption2 Methods
   ' =====================================================================================
   PROPERTY GET SAMILangCount <955> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getSAMILangName <956> ( _                     ' VTable offset = 64
     BYVAL nIndex AS LONG _                             ' __in long nIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   METHOD getSAMILangID <957> ( _                       ' VTable offset = 68
     BYVAL nIndex AS LONG _                             ' __in long nIndex
   ) AS LONG                                            ' __out_retval long *plLangID
   ' =====================================================================================
   PROPERTY GET SAMIStyleCount <958> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getSAMIStyleName <959> ( _                    ' VTable offset = 76
     BYVAL nIndex AS LONG _                             ' __in long nIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPClosedCaption2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlayerApplication
' IID = {40897764-CEAB-47BE-AD4A-8E28537F9BBF}
' IWMPPlayerApplication: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPPlayerApplication_INTERFACE_DEFINED)
    %IWMPPlayerApplication_INTERFACE_DEFINED = 1

INTERFACE IWMPPlayerApplication $IID_IWMPPlayerApplication

   INHERIT IDispatch

   ' =====================================================================================
   METHOD switchToPlayerApplication <1101> ( _          ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD switchToControl <1102> ( _                    ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET playerDocked <1103> ( _                 ' VTable offset = 36
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbPlayerDocked
   ' =====================================================================================
   PROPERTY GET hasDisplay <1104> ( _                   ' VTable offset = 40
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbHasDisplay
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlayerApplication_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPCore3
' IID = {7587C667-628F-499F-88E7-6A6F4E888464}
' IWMPCore3: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPCore2
' ########################################################################################

#IF NOT %DEF(%IWMPCore3_INTERFACE_DEFINED)
    %IWMPCore3_INTERFACE_DEFINED = 1

INTERFACE IWMPCore3 $IID_IWMPCore3

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPCore Methods
   ' =====================================================================================
   METHOD close <3> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <1> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <1> ( _                             ' VTable offset = 36
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET openState <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPOpenState *pwmpos
   ' =====================================================================================
   PROPERTY GET playState <10> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WMPPlayState *pwmpps
   ' =====================================================================================
   PROPERTY GET controls <4> ( _                        ' VTable offset = 48
   ) AS IWMPControls                                    ' __out_retval IWMPControls **ppControl
   ' =====================================================================================
   PROPERTY GET settings <5> ( _                        ' VTable offset = 52
   ) AS IWMPSettings                                    ' __out_retval IWMPSettings **ppSettings
   ' =====================================================================================
   PROPERTY GET currentMedia <6> ( _                    ' VTable offset = 56
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================
   PROPERTY SET currentMedia <6> ( _                    ' VTable offset = 60
     BYVAL ppMedia AS IWMPMedia _                       ' __in IWMPMedia *ppMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mediaCollection <8> ( _                 ' VTable offset = 64
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET playlistCollection <9> ( _              ' VTable offset = 68
   ) AS IWMPPlaylistCollection                          ' __out_retval IWMPPlaylistCollection **ppPlaylistCollection
   ' =====================================================================================
   PROPERTY GET versionInfo <11> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVersionInfo
   ' =====================================================================================
   METHOD launchURL <12> ( _                            ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET network <7> ( _                         ' VTable offset = 80
   ) AS IWMPNetwork                                     ' __out_retval IWMPNetwork **ppQNI
   ' =====================================================================================
   PROPERTY GET currentPlaylist <13> ( _                ' VTable offset = 84
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPL
   ' =====================================================================================
   PROPERTY SET currentPlaylist <13> ( _                ' VTable offset = 88
     BYVAL ppPL AS IWMPPlaylist _                       ' __in IWMPPlaylist *ppPL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cdromCollection <14> ( _                ' VTable offset = 92
   ) AS IWMPCdromCollection                             ' __out_retval IWMPCdromCollection **ppCdromCollection
   ' =====================================================================================
   PROPERTY GET closedCaption <15> ( _                  ' VTable offset = 96
   ) AS IWMPClosedCaption                               ' __out_retval IWMPClosedCaption **ppClosedCaption
   ' =====================================================================================
   PROPERTY GET isOnline <16> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfOnline
   ' =====================================================================================
   PROPERTY GET Error <17> ( _                          ' VTable offset = 104
   ) AS IWMPError                                       ' __out_retval IWMPError **ppError
   ' =====================================================================================
   PROPERTY GET status <18> ( _                         ' VTable offset = 108
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrStatus
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPCore2 Methods
   ' =====================================================================================
   PROPERTY GET dvd <40> ( _                            ' VTable offset = 112
   ) AS IWMPDVD                                         ' __out_retval IWMPDVD **ppDVD
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPCore3 Methods
   ' =====================================================================================
   METHOD newPlaylist <41> ( _                          ' VTable offset = 116
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPlaylist
   ' =====================================================================================
   METHOD newMedia <42> ( _                             ' VTable offset = 120
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPCore3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlayer4
' IID = {6C497D62-8919-413C-82DB-E935FB3EC584}
' IWMPPlayer4: Public interface.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPCore3
' ########################################################################################

#IF NOT %DEF(%IWMPPlayer4_INTERFACE_DEFINED)
    %IWMPPlayer4_INTERFACE_DEFINED = 1

INTERFACE IWMPPlayer4 $IID_IWMPPlayer4

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPCore Methods
   ' =====================================================================================
   METHOD close <3> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <1> ( _                             ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY SET URL <1> ( _                             ' VTable offset = 36
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET openState <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPOpenState *pwmpos
   ' =====================================================================================
   PROPERTY GET playState <10> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WMPPlayState *pwmpps
   ' =====================================================================================
   PROPERTY GET controls <4> ( _                        ' VTable offset = 48
   ) AS IWMPControls                                    ' __out_retval IWMPControls **ppControl
   ' =====================================================================================
   PROPERTY GET settings <5> ( _                        ' VTable offset = 52
   ) AS IWMPSettings                                    ' __out_retval IWMPSettings **ppSettings
   ' =====================================================================================
   PROPERTY GET currentMedia <6> ( _                    ' VTable offset = 56
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================
   PROPERTY SET currentMedia <6> ( _                    ' VTable offset = 60
     BYVAL ppMedia AS IWMPMedia _                       ' __in IWMPMedia *ppMedia
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET mediaCollection <8> ( _                 ' VTable offset = 64
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppMediaCollection
   ' =====================================================================================
   PROPERTY GET playlistCollection <9> ( _              ' VTable offset = 68
   ) AS IWMPPlaylistCollection                          ' __out_retval IWMPPlaylistCollection **ppPlaylistCollection
   ' =====================================================================================
   PROPERTY GET versionInfo <11> ( _                    ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVersionInfo
   ' =====================================================================================
   METHOD launchURL <12> ( _                            ' VTable offset = 76
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET network <7> ( _                         ' VTable offset = 80
   ) AS IWMPNetwork                                     ' __out_retval IWMPNetwork **ppQNI
   ' =====================================================================================
   PROPERTY GET currentPlaylist <13> ( _                ' VTable offset = 84
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPL
   ' =====================================================================================
   PROPERTY SET currentPlaylist <13> ( _                ' VTable offset = 88
     BYVAL ppPL AS IWMPPlaylist _                       ' __in IWMPPlaylist *ppPL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET cdromCollection <14> ( _                ' VTable offset = 92
   ) AS IWMPCdromCollection                             ' __out_retval IWMPCdromCollection **ppCdromCollection
   ' =====================================================================================
   PROPERTY GET closedCaption <15> ( _                  ' VTable offset = 96
   ) AS IWMPClosedCaption                               ' __out_retval IWMPClosedCaption **ppClosedCaption
   ' =====================================================================================
   PROPERTY GET isOnline <16> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pfOnline
   ' =====================================================================================
   PROPERTY GET Error <17> ( _                          ' VTable offset = 104
   ) AS IWMPError                                       ' __out_retval IWMPError **ppError
   ' =====================================================================================
   PROPERTY GET status <18> ( _                         ' VTable offset = 108
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrStatus
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPCore2 Methods
   ' =====================================================================================
   PROPERTY GET dvd <40> ( _                            ' VTable offset = 112
   ) AS IWMPDVD                                         ' __out_retval IWMPDVD **ppDVD
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPCore3 Methods
   ' =====================================================================================
   METHOD newPlaylist <41> ( _                          ' VTable offset = 116
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPlaylist
   ' =====================================================================================
   METHOD newMedia <42> ( _                             ' VTable offset = 120
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppMedia
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPPlayer4 Methods
   ' =====================================================================================
   PROPERTY GET enabled <19> ( _                        ' VTable offset = 124
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET enabled <19> ( _                        ' VTable offset = 128
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET fullScreen <21> ( _                     ' VTable offset = 132
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbFullScreen
   ' =====================================================================================
   PROPERTY SET fullScreen <21> ( _                     ' VTable offset = 136
     BYVAL pbFullScreen AS INTEGER _                    ' __in VARIANT_BOOL pbFullScreen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET enableContextMenu <22> ( _              ' VTable offset = 140
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnableContextMenu
   ' =====================================================================================
   PROPERTY SET enableContextMenu <22> ( _              ' VTable offset = 144
     BYVAL pbEnableContextMenu AS INTEGER _             ' __in VARIANT_BOOL pbEnableContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET uiMode <23> ( _                         ' VTable offset = 148
     BYVAL pbstrMode AS WSTRING _                       ' __in BSTR pbstrMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET uiMode <23> ( _                         ' VTable offset = 152
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrMode
   ' =====================================================================================
   PROPERTY GET stretchToFit <24> ( _                   ' VTable offset = 156
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET stretchToFit <24> ( _                   ' VTable offset = 160
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET windowlessVideo <25> ( _                ' VTable offset = 164
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET windowlessVideo <25> ( _                ' VTable offset = 168
     BYVAL pbEnabled AS INTEGER _                       ' __in VARIANT_BOOL pbEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET isRemote <26> ( _                       ' VTable offset = 172
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsRemote
   ' =====================================================================================
   PROPERTY GET playerApplication <27> ( _              ' VTable offset = 176
   ) AS IWMPPlayerApplication                           ' __out_retval IWMPPlayerApplication **ppIWMPPlayerApplication
   ' =====================================================================================
   METHOD openPlayer <28> ( _                           ' VTable offset = 180
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlayer4_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlayerServices
' IID = {1D01FBDB-ADE2-4C8D-9842-C190B95C3306}
' IWMPPlayerServices: Public interface for Windows Media Player SDK.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPPlayerServices_INTERFACE_DEFINED)
    %IWMPPlayerServices_INTERFACE_DEFINED = 1

INTERFACE IWMPPlayerServices $IID_IWMPPlayerServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD activateUIPlugin ( _                          ' VTable offset = 12
     BYVAL bstrPlugin AS WSTRING _                      ' __in BSTR bstrPlugin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD setTaskPane ( _                               ' VTable offset = 16
     BYVAL bstrTaskPane AS WSTRING _                    ' __in BSTR bstrTaskPane
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD setTaskPaneURL ( _                            ' VTable offset = 20
     BYVAL bstrTaskPane AS WSTRING _                    ' __in BSTR bstrTaskPane
   , BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   , BYVAL bstrFriendlyName AS WSTRING _                ' __in BSTR bstrFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlayerServices_INTERFACE_DEFINED__ */

' ========================================================================================
' WMPSyncState enum
' WMP Sync States
' ========================================================================================

%wmpssUnknown       = 0
%wmpssSynchronizing = %wmpssUnknown       + 1
%wmpssStopped       = %wmpssSynchronizing + 1
%wmpssEstimating    = %wmpssStopped       + 1
%wmpssLast          = %wmpssEstimating    + 1

' ========================================================================================
' WMPDeviceStatus enum
' WMP Sync Device Status
' ========================================================================================

%wmpdsUnknown             = 0
%wmpdsPartnershipExists   = %wmpdsUnknown             + 1
%wmpdsPartnershipDeclined = %wmpdsPartnershipExists   + 1
%wmpdsPartnershipAnother  = %wmpdsPartnershipDeclined + 1
%wmpdsManualDevice        = %wmpdsPartnershipAnother  + 1
%wmpdsNewDevice           = %wmpdsManualDevice        + 1
%wmpdsLast                = %wmpdsNewDevice           + 1

' ########################################################################################
' Interface name = IWMPSyncDevice
' IID = {82A2986C-0293-4FD0-B279-B21B86C058BE}
' IWMPSyncDevice: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPSyncDevice_INTERFACE_DEFINED)
    %IWMPSyncDevice_INTERFACE_DEFINED = 1

INTERFACE IWMPSyncDevice $IID_IWMPSyncDevice

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET friendlyName ( _                        ' VTable offset = 12
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET friendlyName ( _                        ' VTable offset = 16
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET deviceName ( _                          ' VTable offset = 20
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET deviceId ( _                            ' VTable offset = 24
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDeviceId
   ' =====================================================================================
   PROPERTY GET partnershipIndex ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plIndex
   ' =====================================================================================
   PROPERTY GET connected ( _                           ' VTable offset = 32
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbConnected
   ' =====================================================================================
   PROPERTY GET status ( _                              ' VTable offset = 36
   ) AS LONG                                            ' __out_retval WMPDeviceStatus *pwmpds
   ' =====================================================================================
   PROPERTY GET syncState ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPSyncState *pwmpss
   ' =====================================================================================
   PROPERTY GET progress ( _                            ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *plProgress
   ' =====================================================================================
   METHOD getItemInfo ( _                               ' VTable offset = 48
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD createPartnership ( _                         ' VTable offset = 52
     BYVAL vbShowUI AS INTEGER _                        ' __in VARIANT_BOOL vbShowUI
   )                                                    ' void
   ' =====================================================================================
   METHOD deletePartnership ( _                         ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD stop ( _                                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD showSettings ( _                              ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD isIdentical ( _                               ' VTable offset = 72
     BYVAL pDevice AS IWMPSyncDevice _                  ' __in IWMPSyncDevice *pDevice
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPSyncDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPSyncServices
' IID = {8B5050FF-E0A4-4808-B3A8-893A9E1ED894}
' IWMPSyncServices: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPSyncServices_INTERFACE_DEFINED)
    %IWMPSyncServices_INTERFACE_DEFINED = 1

INTERFACE IWMPSyncServices $IID_IWMPSyncServices

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET deviceCount ( _                         ' VTable offset = 12
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getDevice ( _                                 ' VTable offset = 16
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IWMPSyncDevice                                  ' __out_retval IWMPSyncDevice **ppDevice
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPSyncServices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPPlayerServices2
' IID = {1BB1592F-F040-418A-9F71-17C7512B4D70}
' IWMPPlayerServices2: Public interface for Windows Media Player SDK.
' Inherited interface = IWMPPlayerServices
' ########################################################################################

#IF NOT %DEF(%IWMPPlayerServices2_INTERFACE_DEFINED)
    %IWMPPlayerServices2_INTERFACE_DEFINED = 1

INTERFACE IWMPPlayerServices2 $IID_IWMPPlayerServices2

   INHERIT IUnknown

   ' =====================================================================================
   ' IWMPPlayerServices Methods
   ' =====================================================================================
   METHOD activateUIPlugin ( _                          ' VTable offset = 12
     BYVAL bstrPlugin AS WSTRING _                      ' __in BSTR bstrPlugin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD setTaskPane ( _                               ' VTable offset = 16
     BYVAL bstrTaskPane AS WSTRING _                    ' __in BSTR bstrTaskPane
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD setTaskPaneURL ( _                            ' VTable offset = 20
     BYVAL bstrTaskPane AS WSTRING _                    ' __in BSTR bstrTaskPane
   , BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   , BYVAL bstrFriendlyName AS WSTRING _                ' __in BSTR bstrFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPPlayerServices2 Methods
   ' =====================================================================================
   METHOD setBackgroundProcessingPriority ( _           ' VTable offset = 24
     BYVAL bstrPriority AS WSTRING _                    ' __in BSTR bstrPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPPlayerServices2_INTERFACE_DEFINED__ */

' ========================================================================================
' WMPRipState enum
' WMP Ripping States
' ========================================================================================

%wmprsUnknown              = 0
%wmprsRipping              = %wmprsUnknown              + 1
%wmprsStopped              = %wmprsRipping              + 1

' ========================================================================================
' WMPBurnFormat enum
' WMP CD Burning Formats
' ========================================================================================

%wmpbfAudioCD              = 0
%wmpbfDataCD               = %wmpbfAudioCD              + 1

' ========================================================================================
' WMPBurnState enum
' WMP CD Burning States
' ========================================================================================

%wmpbsUnknown              = 0
%wmpbsBusy                 = %wmpbsUnknown              + 1
%wmpbsReady                = %wmpbsBusy                 + 1
%wmpbsWaitingForDisc       = %wmpbsReady                + 1
%wmpbsRefreshStatusPending = %wmpbsWaitingForDisc       + 1
%wmpbsPreparingToBurn      = %wmpbsRefreshStatusPending + 1
%wmpbsBurning              = %wmpbsPreparingToBurn      + 1
%wmpbsStopped              = %wmpbsBurning              + 1
%wmpbsErasing              = %wmpbsStopped              + 1
%wmpbsDownloading          = %wmpbsErasing              + 1

' ========================================================================================
' WMPStringCollectionChangeEventType enum
' WMP String Collection Change Event Type
' ========================================================================================

%wmpsccetUnknown           = 0
%wmpsccetInsert            = %wmpsccetUnknown           + 1
%wmpsccetChange            = %wmpsccetInsert            + 1
%wmpsccetDelete            = %wmpsccetChange            + 1
%wmpsccetClear             = %wmpsccetDelete            + 1
%wmpsccetBeginUpdates      = %wmpsccetClear             + 1
%wmpsccetEndUpdates        = %wmpsccetBeginUpdates      + 1

' ########################################################################################
' Interface name = IWMPCdromRip
' IID = {56E2294F-69ED-4629-A869-AEA72C0DCC2C}
' IWMPCdromRip: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPCdromRip_INTERFACE_DEFINED)
    %IWMPCdromRip_INTERFACE_DEFINED = 1

INTERFACE IWMPCdromRip $IID_IWMPCdromRip

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ripState ( _                            ' VTable offset = 12
   ) AS LONG                                            ' __out_retval WMPRipState *pwmprs
   ' =====================================================================================
   PROPERTY GET ripProgress ( _                         ' VTable offset = 16
   ) AS LONG                                            ' __out_retval long *plProgress
   ' =====================================================================================
   METHOD startRip ( _                                  ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD stopRip ( _                                   ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPCdromRip_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPCdromBurn
' IID = {BD94DBEB-417F-4928-AA06-087D56ED9B59}
' IWMPCdromBurn: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPCdromBurn_INTERFACE_DEFINED)
    %IWMPCdromBurn_INTERFACE_DEFINED = 1

INTERFACE IWMPCdromBurn $IID_IWMPCdromBurn

   INHERIT IAutomation

   ' =====================================================================================
   METHOD isAvailable ( _                               ' VTable offset = 12
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pIsAvailable
   ' =====================================================================================
   METHOD getItemInfo ( _                               ' VTable offset = 16
     BYVAL bstrItem AS WSTRING _                        ' __in BSTR bstrItem
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   PROPERTY GET label ( _                               ' VTable offset = 20
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET label ( _                               ' VTable offset = 24
     BYVAL pbstrLabel AS WSTRING _                      ' __in BSTR pbstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET burnFormat ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __out_retval WMPBurnFormat *pwmpbf
   ' =====================================================================================
   PROPERTY SET burnFormat ( _                          ' VTable offset = 32
     BYVAL pwmpbf AS LONG _                             ' __in WMPBurnFormat pwmpbf
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET burnPlaylist ( _                        ' VTable offset = 36
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPlaylist
   ' =====================================================================================
   PROPERTY SET burnPlaylist ( _                        ' VTable offset = 40
     BYVAL ppPlaylist AS IWMPPlaylist _                 ' __in IWMPPlaylist *ppPlaylist
   )                                                    ' void
   ' =====================================================================================
   METHOD refreshStatus ( _                             ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET burnState ( _                           ' VTable offset = 48
   ) AS LONG                                            ' __out_retval WMPBurnState *pwmpbs
   ' =====================================================================================
   PROPERTY GET burnProgress ( _                        ' VTable offset = 52
   ) AS LONG                                            ' __out_retval long *plProgress
   ' =====================================================================================
   METHOD startBurn ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD stopBurn ( _                                  ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD erase ( _                                     ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPCdromBurn_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPQuery
' IID = {A00918F3-A6B0-4BFB-9189-FD834C7BC5A5}
' IWMPQuery: Public interface for Windows Media Player SDK.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMPQuery_INTERFACE_DEFINED)
    %IWMPQuery_INTERFACE_DEFINED = 1

INTERFACE IWMPQuery $IID_IWMPQuery

   INHERIT IDispatch

   ' =====================================================================================
   METHOD addCondition <1351> ( _                       ' VTable offset = 28
     BYVAL bstrAttribute AS WSTRING _                   ' __in BSTR bstrAttribute
   , BYVAL bstrOperator AS WSTRING _                    ' __in BSTR bstrOperator
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   METHOD beginNextGroup <1352> ( _                     ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPQuery_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPMediaCollection2
' IID = {8BA957F5-FD8C-4791-B82D-F840401EE474}
' IWMPMediaCollection2: Public interface for Windows Media Player SDK.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPMediaCollection
' ########################################################################################

#IF NOT %DEF(%IWMPMediaCollection2_INTERFACE_DEFINED)
    %IWMPMediaCollection2_INTERFACE_DEFINED = 1

INTERFACE IWMPMediaCollection2 $IID_IWMPMediaCollection2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPMediaCollection Methods
   ' =====================================================================================
   METHOD add <452> ( _                                 ' VTable offset = 28
     BYVAL bstrURL AS WSTRING _                         ' __in BSTR bstrURL
   ) AS IWMPMedia                                       ' __out_retval IWMPMedia **ppItem
   ' =====================================================================================
   METHOD getAll <453> ( _                              ' VTable offset = 32
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByName <454> ( _                           ' VTable offset = 36
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByGenre <455> ( _                          ' VTable offset = 40
     BYVAL bstrGenre AS WSTRING _                       ' __in BSTR bstrGenre
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByAuthor <456> ( _                         ' VTable offset = 44
     BYVAL bstrAuthor AS WSTRING _                      ' __in BSTR bstrAuthor
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByAlbum <457> ( _                          ' VTable offset = 48
     BYVAL bstrAlbum AS WSTRING _                       ' __in BSTR bstrAlbum
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD getByAttribute <458> ( _                      ' VTable offset = 52
     BYVAL bstrAttribute AS WSTRING _                   ' __in BSTR bstrAttribute
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================
   METHOD remove <459> ( _                              ' VTable offset = 56
     BYVAL pItem AS IWMPMedia _                         ' __in IWMPMedia *pItem
   , BYVAL varfDeleteFile AS INTEGER _                  ' __in VARIANT_BOOL varfDeleteFile
   )                                                    ' void
   ' =====================================================================================
   METHOD getAttributeStringCollection <461> ( _        ' VTable offset = 60
     BYVAL bstrAttribute AS WSTRING _                   ' __in BSTR bstrAttribute
   , BYVAL bstrMediaType AS WSTRING _                   ' __in BSTR bstrMediaType
   ) AS IWMPStringCollection                            ' __out_retval IWMPStringCollection **ppStringCollection
   ' =====================================================================================
   METHOD getMediaAtom <470> ( _                        ' VTable offset = 64
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS LONG                                            ' __out_retval long *plAtom
   ' =====================================================================================
   METHOD setDeleted <471> ( _                          ' VTable offset = 68
     BYVAL pItem AS IWMPMedia _                         ' __in IWMPMedia *pItem
   , BYVAL varfIsDeleted AS INTEGER _                   ' __in VARIANT_BOOL varfIsDeleted
   )                                                    ' void
   ' =====================================================================================
   METHOD isDeleted <472> ( _                           ' VTable offset = 72
     BYVAL pItem AS IWMPMedia _                         ' __in IWMPMedia *pItem
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvarfIsDeleted
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPMediaCollection2 Methods
   ' =====================================================================================
   METHOD createQuery <1401> ( _                        ' VTable offset = 76
   ) AS IWMPQuery                                       ' __out_retval IWMPQuery **ppQuery
   ' =====================================================================================
   METHOD getPlaylistByQuery <1402> ( _                 ' VTable offset = 80
     BYVAL pQuery AS IWMPQuery _                        ' __in IWMPQuery *pQuery
   , BYVAL bstrMediaType AS WSTRING _                   ' __in BSTR bstrMediaType
   , BYVAL bstrSortAttribute AS WSTRING _               ' __in BSTR bstrSortAttribute
   , BYVAL fSortAscending AS INTEGER _                  ' __in VARIANT_BOOL fSortAscending
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppPlaylist
   ' =====================================================================================
   METHOD getStringCollectionByQuery <1403> ( _         ' VTable offset = 84
     BYVAL bstrAttribute AS WSTRING _                   ' __in BSTR bstrAttribute
   , BYVAL pQuery AS IWMPQuery _                        ' __in IWMPQuery *pQuery
   , BYVAL bstrMediaType AS WSTRING _                   ' __in BSTR bstrMediaType
   , BYVAL bstrSortAttribute AS WSTRING _               ' __in BSTR bstrSortAttribute
   , BYVAL fSortAscending AS INTEGER _                  ' __in VARIANT_BOOL fSortAscending
   ) AS IWMPStringCollection                            ' __out_retval IWMPStringCollection **ppStringCollection
   ' =====================================================================================
   METHOD getByAttributeAndMediaType <1404> ( _         ' VTable offset = 88
     BYVAL bstrAttribute AS WSTRING _                   ' __in BSTR bstrAttribute
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   , BYVAL bstrMediaType AS WSTRING _                   ' __in BSTR bstrMediaType
   ) AS IWMPPlaylist                                    ' __out_retval IWMPPlaylist **ppMediaItems
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPMediaCollection2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPStringCollection2
' IID = {46AD648D-53F1-4A74-92E2-2A1B68D63FD4}
' IWMPStringCollection2: Public interface for Windows Media Player SDK.
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IWMPStringCollection
' ########################################################################################

#IF NOT %DEF(%IWMPStringCollection2_INTERFACE_DEFINED)
    %IWMPStringCollection2_INTERFACE_DEFINED = 1

INTERFACE IWMPStringCollection2 $IID_IWMPStringCollection2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWMPStringCollection Methods
   ' =====================================================================================
   PROPERTY GET count <401> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD Item <402> ( _                                ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrString
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPStringCollection2 Methods
   ' =====================================================================================
   METHOD isIdentical <1451> ( _                        ' VTable offset = 36
     BYVAL pIWMPStringCollection2 AS IWMPStringCollection2 _ ' __in IWMPStringCollection2 *pIWMPStringCollection2
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================
   METHOD getItemInfo <1452> ( _                        ' VTable offset = 40
     BYVAL lCollectionIndex AS LONG _                   ' __in long lCollectionIndex
   , BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrValue
   ' =====================================================================================
   METHOD getAttributeCountByType <1453> ( _            ' VTable offset = 44
     BYVAL lCollectionIndex AS LONG _                   ' __in long lCollectionIndex
   , BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getItemInfoByType <1454> ( _                  ' VTable offset = 48
     BYVAL lCollectionIndex AS LONG _                   ' __in long lCollectionIndex
   , BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   , BYVAL bstrLanguage AS WSTRING _                    ' __in BSTR bstrLanguage
   , BYVAL lAttributeIndex AS LONG _                    ' __in long lAttributeIndex
   ) AS VARIANT                                         ' __out_retval VARIANT *pvarValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPStringCollection2_INTERFACE_DEFINED__ */

' ========================================================================================
' WMPLibraryType enum
' WMP Library Types
' ========================================================================================

%wmpltUnknown        = 0
%wmpltAll            = %wmpltUnknown + 1
%wmpltLocal          = %wmpltAll     + 1
%wmpltRemote         = %wmpltLocal   + 1
%wmpltDisc           = %wmpltRemote  + 1
%wmpltPortableDevice = %wmpltDisc    + 1

' ########################################################################################
' Interface name = IWMPLibrary
' IID = {3DF47861-7DF1-4C1F-A81B-4C26F0F7A7C6}
' IWMPLibrary: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPLibrary_INTERFACE_DEFINED)
    %IWMPLibrary_INTERFACE_DEFINED = 1

INTERFACE IWMPLibrary $IID_IWMPLibrary

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET type ( _                                ' VTable offset = 16
   ) AS LONG                                            ' __out_retval WMPLibraryType *pwmplt
   ' =====================================================================================
   PROPERTY GET mediaCollection ( _                     ' VTable offset = 20
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppIWMPMediaCollection
   ' =====================================================================================
   METHOD isIdentical ( _                               ' VTable offset = 24
     BYVAL pIWMPLibrary AS IWMPLibrary _                ' __in IWMPLibrary *pIWMPLibrary
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPLibrary_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPLibraryServices
' IID = {39C2F8D5-1CF2-4D5E-AE09-D73492CF9EAA}
' IWMPLibraryServices: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPLibraryServices_INTERFACE_DEFINED)
    %IWMPLibraryServices_INTERFACE_DEFINED = 1

INTERFACE IWMPLibraryServices $IID_IWMPLibraryServices

   INHERIT IAutomation

   ' =====================================================================================
   METHOD getCountByType ( _                            ' VTable offset = 12
     BYVAL wmplt AS LONG _                              ' __in WMPLibraryType wmplt
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD getLibraryByType ( _                          ' VTable offset = 16
     BYVAL wmplt AS LONG _                              ' __in WMPLibraryType wmplt
   , BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IWMPLibrary                                     ' __out_retval IWMPLibrary **ppIWMPLibrary
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPLibraryServices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPLibrarySharingServices
' IID = {82CBA86B-9F04-474B-A365-D6DD1466E541}
' IWMPLibrarySharingServices: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPLibrarySharingServices_INTERFACE_DEFINED)
    %IWMPLibrarySharingServices_INTERFACE_DEFINED = 1

INTERFACE IWMPLibrarySharingServices $IID_IWMPLibrarySharingServices

   INHERIT IAutomation

   ' =====================================================================================
   METHOD isLibraryShared ( _                           ' VTable offset = 12
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbShared
   ' =====================================================================================
   METHOD isLibrarySharingEnabled ( _                   ' VTable offset = 16
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbEnabled
   ' =====================================================================================
   METHOD showLibrarySharing ( _                        ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPLibrarySharingServices_INTERFACE_DEFINED__ */

' ========================================================================================
' WMPFolderScanState enum
' WMP Folder Scan States
' ========================================================================================

%wmpfssUnknown  = 0
%wmpfssScanning = %wmpfssUnknown  + 1
%wmpfssUpdating = %wmpfssScanning + 1
%wmpfssStopped  = %wmpfssUpdating + 1

' ########################################################################################
' Interface name = IWMPFolderMonitorServices
' IID = {788C8743-E57F-439D-A468-5BC77F2E59C6}
' IWMPFolderMonitorServices: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPFolderMonitorServices_INTERFACE_DEFINED)
    %IWMPFolderMonitorServices_INTERFACE_DEFINED = 1

INTERFACE IWMPFolderMonitorServices $IID_IWMPFolderMonitorServices

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET count ( _                               ' VTable offset = 12
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 16
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrFolder
   ' =====================================================================================
   METHOD add ( _                                       ' VTable offset = 20
     BYVAL bstrFolder AS WSTRING _                      ' __in BSTR bstrFolder
   )                                                    ' void
   ' =====================================================================================
   METHOD remove ( _                                    ' VTable offset = 24
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET scanState ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __out_retval WMPFolderScanState *pwmpfss
   ' =====================================================================================
   PROPERTY GET currentFolder ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrFolder
   ' =====================================================================================
   PROPERTY GET scannedFilesCount ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   PROPERTY GET addedFilesCount ( _                     ' VTable offset = 40
   ) AS LONG                                            ' __out_retval long *plCount
   ' =====================================================================================
   PROPERTY GET updateProgress ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *plProgress
   ' =====================================================================================
   METHOD startScan ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD stopScan ( _                                  ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPFolderMonitorServices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPSyncDevice2
' IID = {88AFB4B2-140A-44D2-91E6-4543DA467CD1}
' IWMPSyncDevice2: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IWMPSyncDevice
' ########################################################################################

#IF NOT %DEF(%IWMPSyncDevice2_INTERFACE_DEFINED)
    %IWMPSyncDevice2_INTERFACE_DEFINED = 1

INTERFACE IWMPSyncDevice2 $IID_IWMPSyncDevice2

   INHERIT IAutomation

   ' =====================================================================================
   ' IWMPSyncDevice methods
   ' =====================================================================================
   PROPERTY GET friendlyName ( _                        ' VTable offset = 12
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET friendlyName ( _                        ' VTable offset = 16
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET deviceName ( _                          ' VTable offset = 20
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET deviceId ( _                            ' VTable offset = 24
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDeviceId
   ' =====================================================================================
   PROPERTY GET partnershipIndex ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plIndex
   ' =====================================================================================
   PROPERTY GET connected ( _                           ' VTable offset = 32
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbConnected
   ' =====================================================================================
   PROPERTY GET status ( _                              ' VTable offset = 36
   ) AS LONG                                            ' __out_retval WMPDeviceStatus *pwmpds
   ' =====================================================================================
   PROPERTY GET syncState ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPSyncState *pwmpss
   ' =====================================================================================
   PROPERTY GET progress ( _                            ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *plProgress
   ' =====================================================================================
   METHOD getItemInfo ( _                               ' VTable offset = 48
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD createPartnership ( _                         ' VTable offset = 52
     BYVAL vbShowUI AS INTEGER _                        ' __in VARIANT_BOOL vbShowUI
   )                                                    ' void
   ' =====================================================================================
   METHOD deletePartnership ( _                         ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD stop ( _                                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD showSettings ( _                              ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD isIdentical ( _                               ' VTable offset = 72
     BYVAL pDevice AS IWMPSyncDevice _                  ' __in IWMPSyncDevice *pDevice
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPSyncDevice2 Methods
   ' =====================================================================================
   METHOD setItemInfo ( _                               ' VTable offset = 76
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPSyncDevice2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPSyncDevice3
' IID = {B22C85F9-263C-4372-A0DA-B518DB9B4098}
' IWMPSyncDevice3: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IWMPSyncDevice2
' ########################################################################################

#IF NOT %DEF(%IWMPSyncDevice3_INTERFACE_DEFINED)
    %IWMPSyncDevice3_INTERFACE_DEFINED = 1

INTERFACE IWMPSyncDevice3 $IID_IWMPSyncDevice3

   INHERIT IAutomation

   ' =====================================================================================
   ' IWMPSyncDevice methods
   ' =====================================================================================
   PROPERTY GET friendlyName ( _                        ' VTable offset = 12
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET friendlyName ( _                        ' VTable offset = 16
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET deviceName ( _                          ' VTable offset = 20
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET deviceId ( _                            ' VTable offset = 24
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrDeviceId
   ' =====================================================================================
   PROPERTY GET partnershipIndex ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *plIndex
   ' =====================================================================================
   PROPERTY GET connected ( _                           ' VTable offset = 32
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbConnected
   ' =====================================================================================
   PROPERTY GET status ( _                              ' VTable offset = 36
   ) AS LONG                                            ' __out_retval WMPDeviceStatus *pwmpds
   ' =====================================================================================
   PROPERTY GET syncState ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __out_retval WMPSyncState *pwmpss
   ' =====================================================================================
   PROPERTY GET progress ( _                            ' VTable offset = 44
   ) AS LONG                                            ' __out_retval long *plProgress
   ' =====================================================================================
   METHOD getItemInfo ( _                               ' VTable offset = 48
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================
   METHOD createPartnership ( _                         ' VTable offset = 52
     BYVAL vbShowUI AS INTEGER _                        ' __in VARIANT_BOOL vbShowUI
   )                                                    ' void
   ' =====================================================================================
   METHOD deletePartnership ( _                         ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD stop ( _                                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD showSettings ( _                              ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD isIdentical ( _                               ' VTable offset = 72
     BYVAL pDevice AS IWMPSyncDevice _                  ' __in IWMPSyncDevice *pDevice
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPSyncDevice2 Methods
   ' =====================================================================================
   METHOD setItemInfo ( _                               ' VTable offset = 76
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   , BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPSyncDevice3 Methods
   ' =====================================================================================
   METHOD estimateSyncSize ( _                          ' VTable offset = 80
     BYVAL pNonRulePlaylist AS IWMPPlaylist _           ' __in IWMPPlaylist *pNonRulePlaylist
   , BYVAL pRulesPlaylist AS IWMPPlaylist _             ' __in IWMPPlaylist *pRulesPlaylist
   )                                                    ' void
   ' =====================================================================================
   METHOD cancelEstimation ( _                          ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPSyncDevice3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPLibrary2
' IID = {DD578A4E-79B1-426C-BF8F-3ADD9072500B}
' IWMPLibrary2: Public interface for Windows Media Player SDK.
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IWMPLibrary
' ########################################################################################

#IF NOT %DEF(%IWMPLibrary2_INTERFACE_DEFINED)
    %IWMPLibrary2_INTERFACE_DEFINED = 1

INTERFACE IWMPLibrary2 $IID_IWMPLibrary2

   INHERIT IAutomation

   ' =====================================================================================
   ' IWMPLibrary Methods
   ' =====================================================================================
   PROPERTY GET name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET type ( _                                ' VTable offset = 16
   ) AS LONG                                            ' __out_retval WMPLibraryType *pwmplt
   ' =====================================================================================
   PROPERTY GET mediaCollection ( _                     ' VTable offset = 20
   ) AS IWMPMediaCollection                             ' __out_retval IWMPMediaCollection **ppIWMPMediaCollection
   ' =====================================================================================
   METHOD isIdentical ( _                               ' VTable offset = 24
     BYVAL pIWMPLibrary AS IWMPLibrary _                ' __in IWMPLibrary *pIWMPLibrary
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *pvbool
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPLibrary2 Methods
   ' =====================================================================================
   METHOD getItemInfo ( _                               ' VTable offset = 28
     BYVAL bstrItemName AS WSTRING _                    ' __in BSTR bstrItemName
   ) AS WSTRING                                         ' __out_retval BSTR *pbstrVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPLibrary2_INTERFACE_DEFINED__ */

' ########################################################################################
' Class CWMPOCXEvents
' Interface name = _WMPOCXEvents
' IID = {6BF52A51-394A-11D3-B153-00C04F79FAA6}
' _WMPOCXEvents: Public interface.
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CWMPOCXEvents GUID$("{888AD4A1-9F5C-49DA-9708-4CC850A18E11}") AS EVENT

'INTERFACE WMPOCXEventsImpl GUID$("{6BF52A51-394A-11D3-B153-00C04F79FAA6}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OpenStateChange <5001> ( _
'     BYVAL NewState AS LONG _                           ' [in] NewState VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlayStateChange <5101> ( _
'     BYVAL NewState AS LONG _                           ' [in] NewState VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AudioLanguageChange <5102> ( _
'     BYVAL LangID AS LONG _                             ' [in] LangID VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StatusChange <5002>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ScriptCommand <5301> ( _
'     BYVAL scType AS WSTRING _                          ' [in] scType VT_BSTR
'   , BYVAL Param AS WSTRING _                           ' [in] Param VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NewStream <5403>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Disconnect <5401> ( _
'     BYVAL Result AS LONG _                             ' [in] Result VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Buffering <5402> ( _
'     BYVAL Start AS INTEGER _                           ' [in] Start VT_BOOL <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Error <5501>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Warning <5601> ( _
'     BYVAL WarningType AS LONG _                        ' [in] WarningType VT_I4 <Long>
'   , BYVAL Param AS LONG _                              ' [in] Param VT_I4 <Long>
'   , BYVAL Description AS WSTRING _                     ' [in] Description VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EndOfStream <5201> ( _
'     BYVAL Result AS LONG _                             ' [in] Result VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PositionChange <5202> ( _
'     BYVAL oldPosition AS DOUBLE _                      ' [in] oldPosition VT_R8 <Double>
'   , BYVAL newPosition AS DOUBLE _                      ' [in] newPosition VT_R8 <Double>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MarkerHit <5203> ( _
'     BYVAL MarkerNum AS LONG _                          ' [in] MarkerNum VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DurationUnitChange <5204> ( _
'     BYVAL NewDurationUnit AS LONG _                    ' [in] NewDurationUnit VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CdromMediaChange <5701> ( _
'     BYVAL CdromNum AS LONG _                           ' [in] CdromNum VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlaylistChange <5801> ( _
'     BYVAL Playlist AS IDispatch _                      ' [in] *Playlist VT_DISPATCH <IDispatch>
'   , BYVAL change AS LONG _                             ' [in] change WMPPlaylistChangeEventType <enum>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CurrentPlaylistChange <5804> ( _
'     BYVAL change AS LONG _                             ' [in] change WMPPlaylistChangeEventType <enum>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CurrentPlaylistItemAvailable <5805> ( _
'     BYVAL bstrItemName AS WSTRING _                    ' [in] bstrItemName VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaChange <5802> ( _
'     BYVAL Item AS IDispatch _                          ' [in] *Item VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CurrentMediaItemAvailable <5803> ( _
'     BYVAL bstrItemName AS WSTRING _                    ' [in] bstrItemName VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CurrentItemChange <5806> ( _
'     BYVAL pdispMedia AS IDispatch _                    ' [in] *pdispMedia VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaCollectionChange <5807>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaCollectionAttributeStringAdded <5808> ( _
'     BYVAL bstrAttribName AS WSTRING _                  ' [in] bstrAttribName VT_BSTR
'   , BYVAL bstrAttribVal AS WSTRING _                   ' [in] bstrAttribVal VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaCollectionAttributeStringRemoved <5809> ( _
'     BYVAL bstrAttribName AS WSTRING _                  ' [in] bstrAttribName VT_BSTR
'   , BYVAL bstrAttribVal AS WSTRING _                   ' [in] bstrAttribVal VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaCollectionAttributeStringChanged <5820> ( _
'     BYVAL bstrAttribName AS WSTRING _                  ' [in] bstrAttribName VT_BSTR
'   , BYVAL bstrOldAttribVal AS WSTRING _                ' [in] bstrOldAttribVal VT_BSTR
'   , BYVAL bstrNewAttribVal AS WSTRING _                ' [in] bstrNewAttribVal VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlaylistCollectionChange <5810>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlaylistCollectionPlaylistAdded <5811> ( _
'     BYVAL bstrPlaylistName AS WSTRING _                ' [in] bstrPlaylistName VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlaylistCollectionPlaylistRemoved <5812> ( _
'     BYVAL bstrPlaylistName AS WSTRING _                ' [in] bstrPlaylistName VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlaylistCollectionPlaylistSetAsDeleted <5818> ( _
'     BYVAL bstrPlaylistName AS WSTRING _                ' [in] bstrPlaylistName VT_BSTR
'   , BYVAL varfIsDeleted AS INTEGER _                   ' [in] varfIsDeleted VT_BOOL <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ModeChange <5819> ( _
'     BYVAL ModeName AS WSTRING _                        ' [in] ModeName VT_BSTR
'   , BYVAL NewValue AS INTEGER _                        ' [in] NewValue VT_BOOL <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaError <5821> ( _
'     BYVAL pMediaObject AS IDispatch _                  ' [in] *pMediaObject VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OpenPlaylistSwitch <5823> ( _
'     BYVAL pItem AS IDispatch _                         ' [in] *pItem VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DomainChange <5822> ( _
'     BYVAL strDomain AS WSTRING _                       ' [in] strDomain VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SwitchedToPlayerApplication <6501>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SwitchedToControl <6502>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlayerDockedStateChange <6503>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlayerReconnect <6504>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Click <6505> ( _
'     BYVAL nButton AS INTEGER _                         ' [in] nButton VT_I2 <Integer>
'   , BYVAL nShiftState AS INTEGER _                     ' [in] nShiftState VT_I2 <Integer>
'   , BYVAL fX AS LONG _                                 ' [in] fX VT_I4 <Long>
'   , BYVAL fY AS LONG _                                 ' [in] fY VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DoubleClick <6506> ( _
'     BYVAL nButton AS INTEGER _                         ' [in] nButton VT_I2 <Integer>
'   , BYVAL nShiftState AS INTEGER _                     ' [in] nShiftState VT_I2 <Integer>
'   , BYVAL fX AS LONG _                                 ' [in] fX VT_I4 <Long>
'   , BYVAL fY AS LONG _                                 ' [in] fY VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <6507> ( _
'     BYVAL nKeyCode AS INTEGER _                        ' [in] nKeyCode VT_I2 <Integer>
'   , BYVAL nShiftState AS INTEGER _                     ' [in] nShiftState VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <6508> ( _
'     BYVAL nKeyAscii AS INTEGER _                       ' [in] nKeyAscii VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <6509> ( _
'     BYVAL nKeyCode AS INTEGER _                        ' [in] nKeyCode VT_I2 <Integer>
'   , BYVAL nShiftState AS INTEGER _                     ' [in] nShiftState VT_I2 <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <6510> ( _
'     BYVAL nButton AS INTEGER _                         ' [in] nButton VT_I2 <Integer>
'   , BYVAL nShiftState AS INTEGER _                     ' [in] nShiftState VT_I2 <Integer>
'   , BYVAL fX AS LONG _                                 ' [in] fX VT_I4 <Long>
'   , BYVAL fY AS LONG _                                 ' [in] fY VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <6511> ( _
'     BYVAL nButton AS INTEGER _                         ' [in] nButton VT_I2 <Integer>
'   , BYVAL nShiftState AS INTEGER _                     ' [in] nShiftState VT_I2 <Integer>
'   , BYVAL fX AS LONG _                                 ' [in] fX VT_I4 <Long>
'   , BYVAL fY AS LONG _                                 ' [in] fY VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <6512> ( _
'     BYVAL nButton AS INTEGER _                         ' [in] nButton VT_I2 <Integer>
'   , BYVAL nShiftState AS INTEGER _                     ' [in] nShiftState VT_I2 <Integer>
'   , BYVAL fX AS LONG _                                 ' [in] fX VT_I4 <Long>
'   , BYVAL fY AS LONG _                                 ' [in] fY VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceConnect <6513> ( _
'     BYVAL pDevice AS IWMPSyncDevice _                  ' [in] *pDevice IWMPSyncDevice <interface>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceDisconnect <6514> ( _
'     BYVAL pDevice AS IWMPSyncDevice _                  ' [in] *pDevice IWMPSyncDevice <interface>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceStatusChange <6515> ( _
'     BYVAL pDevice AS IWMPSyncDevice _                  ' [in] *pDevice IWMPSyncDevice <interface>
'   , BYVAL NewStatus AS LONG _                          ' [in] NewStatus WMPDeviceStatus <enum>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceSyncStateChange <6516> ( _
'     BYVAL pDevice AS IWMPSyncDevice _                  ' [in] *pDevice IWMPSyncDevice <interface>
'   , BYVAL NewState AS LONG _                           ' [in] NewState WMPSyncState <enum>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceSyncError <6517> ( _
'     BYVAL pDevice AS IWMPSyncDevice _                  ' [in] *pDevice IWMPSyncDevice <interface>
'   , BYVAL pMedia AS IDispatch _                        ' [in] *pMedia VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CreatePartnershipComplete <6518> ( _
'     BYVAL pDevice AS IWMPSyncDevice _                  ' [in] *pDevice IWMPSyncDevice <interface>
'   , BYVAL hrResult AS LONG _                           ' [in] hrResult VT_HRESULT <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceEstimation <6527> ( _
'     BYVAL pDevice AS IWMPSyncDevice _                  ' [in] *pDevice IWMPSyncDevice <interface>
'   , BYVAL hrResult AS LONG _                           ' [in] hrResult VT_HRESULT <Long>
'   , BYVAL qwEstimatedUsedSpace AS QUAD _               ' [in] qwEstimatedUsedSpace VT_I8 <Quad>
'   , BYVAL qwEstimatedSpace AS QUAD _                   ' [in] qwEstimatedSpace VT_I8 <Quad>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CdromRipStateChange <6519> ( _
'     BYVAL pCdromRip AS IWMPCdromRip _                  ' [in] *pCdromRip IWMPCdromRip <interface>
'   , BYVAL wmprs AS LONG _                              ' [in] wmprs WMPRipState <enum>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CdromRipMediaError <6520> ( _
'     BYVAL pCdromRip AS IWMPCdromRip _                  ' [in] *pCdromRip IWMPCdromRip <interface>
'   , BYVAL pMedia AS IDispatch _                        ' [in] *pMedia VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CdromBurnStateChange <6521> ( _
'     BYVAL pCdromBurn AS IWMPCdromBurn _                ' [in] *pCdromBurn IWMPCdromBurn <interface>
'   , BYVAL wmpbs AS LONG _                              ' [in] wmpbs WMPBurnState <enum>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CdromBurnMediaError <6522> ( _
'     BYVAL pCdromBurn AS IWMPCdromBurn _                ' [in] *pCdromBurn IWMPCdromBurn <interface>
'   , BYVAL pMedia AS IDispatch _                        ' [in] *pMedia VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD CdromBurnError <6523> ( _
'     BYVAL pCdromBurn AS IWMPCdromBurn _                ' [in] *pCdromBurn IWMPCdromBurn <interface>
'   , BYVAL hrError AS LONG _                            ' [in] hrError VT_HRESULT <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD LibraryConnect <6524> ( _
'     BYVAL pLibrary AS IWMPLibrary _                    ' [in] *pLibrary IWMPLibrary <interface>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD LibraryDisconnect <6525> ( _
'     BYVAL pLibrary AS IWMPLibrary _                    ' [in] *pLibrary IWMPLibrary <interface>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD FolderScanStateChange <6526> ( _
'     BYVAL wmpfss AS LONG _                             ' [in] wmpfss WMPFolderScanState <enum>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StringCollectionChange <5824> ( _
'     BYVAL pdispStringCollection AS IDispatch _         ' [in] *pdispStringCollection VT_DISPATCH <IDispatch>
'   , BYVAL change AS LONG _                             ' [in] change WMPStringCollectionChangeEventType <enum>
'   , BYVAL lCollectionIndex AS LONG _                   ' [in] lCollectionIndex VT_I4 <Long>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaCollectionMediaAdded <5825> ( _
'     BYVAL pdispMedia AS IDispatch _                    ' [in] *pdispMedia VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MediaCollectionMediaRemoved <5826> ( _
'     BYVAL pdispMedia AS IDispatch _                    ' [in] *pdispMedia VT_DISPATCH <IDispatch>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
