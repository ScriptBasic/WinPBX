' ########################################################################################
' Microsoft Windows
' File: AgtSvr.inc
' Library name: AgentServerObjects
' Version: 2.0, Locale ID = 0
' Contents: Microsoft Agent Server 2.0
' Library GUID: {F5BE8BC2-7DE6-11D0-91FE-00C04FD701A5}
' Path: C:\WINDOWS\msagent\AgentSvr.exe
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AGTSVR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

%AGENT_VERSION_MAJOR = 2
%AGENT_VERSION_MINOR = 0

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {D45FD2FC-5C6E-11D1-9EC1-00C04FD7081F}
$PROGID_AgentServer2 = "Agent.Server.2"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {D45FD2FC-5C6E-11D1-9EC1-00C04FD7081F}
$PROGID_AgentServer = "Agent.Server"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AgentServer                 = GUID$("{D45FD2FC-5C6E-11D1-9EC1-00C04FD7081F}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAgent                        = GUID$("{A7B93C91-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentAudioOutputProperties   = GUID$("{A7B93C89-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentAudioOutputPropertiesEx = GUID$("{A7B93CA0-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentBalloon                 = GUID$("{A7B93C8D-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentBalloonEx               = GUID$("{D7A6D440-8872-11D1-9EC6-00C04FD7081F}")
$IID_IAgentCharacter               = GUID$("{A7B93C8F-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentCharacterEx             = GUID$("{98BBE491-2EED-11D1-ACAC-00C04FD97575}")
$IID_IAgentCommand                 = GUID$("{A7B93C83-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentCommandEx               = GUID$("{B0913412-3B44-11D1-ACBA-00C04FD97575}")
$IID_IAgentCommands                = GUID$("{A7B93C85-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentCommandsEx              = GUID$("{6BA90C00-3910-11D1-ACB3-00C04FD97575}")
$IID_IAgentCommandWindow           = GUID$("{6D0ECB23-9968-11D0-AC6E-00C04FD97575}")
$IID_IAgentEx                      = GUID$("{48D12BA0-5B77-11D1-9EC1-00C04FD7081F}")
$IID_IAgentNotifySink              = GUID$("{00D18159-8466-11D0-AC63-00C04FD97575}")
$IID_IAgentNotifySinkEx            = GUID$("{08C75162-3C9C-11D1-91FE-00C04FD701A5}")
$IID_IAgentPropertySheet           = GUID$("{A7B93C8B-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentSpeechInputProperties   = GUID$("{A7B93C87-7B81-11D0-AC5F-00C04FD97575}")
$IID_IAgentUserInput               = GUID$("{A7B93C80-7B81-11D0-AC5F-00C04FD97575}")

%NeverMoved                            = 0
%UserMoved                             = 1
%ProgramMoved                          = 2
%OtherProgramMoved                     = 3
%SystemMoved                           = 4
%NeverShown                            = 0
%UserHid                               = 1
%UserShowed                            = 2
%ProgramHid                            = 3
%ProgramShowed                         = 4
%OtherProgramHid                       = 5
%OtherProgramShowed                    = 6
%UserHidViaCharacterMenu               = 7
%UserHidViaTaskbarIcon                 = %UserHid

%CSHELPCAUSE_COMMAND                   = 1
%CSHELPCAUSE_OTHERPROGRAM              = 2
%CSHELPCAUSE_OPENCOMMANDSWINDOW        = 3
%CSHELPCAUSE_CLOSECOMMANDSWINDOW       = 4
%CSHELPCAUSE_SHOWCHARACTER             = 5
%CSHELPCAUSE_HIDECHARACTER             = 6
%CSHELPCAUSE_CHARACTER                 = 7

%ACTIVATE_NOTTOPMOST                   = 0
%ACTIVATE_TOPMOST                      = 1
%ACTIVATE_NOTACTIVE                    = 0
%ACTIVATE_ACTIVE                       = 1
%ACTIVATE_INPUTACTIVE                  = 2
%PREPARE_ANIMATION                     = 0
%PREPARE_STATE                         = 1
%PREPARE_WAVE                          = 2

%STOP_TYPE_PLAY                        = &H1
%STOP_TYPE_MOVE                        = &H2
%STOP_TYPE_SPEAK                       = &H4
%STOP_TYPE_PREPARE                     = &H8
%STOP_TYPE_NONQUEUEDPREPARE            = &H10
%STOP_TYPE_VISIBLE                     = &H20
%STOP_TYPE_ALL                         = &Hffffffff

%BALLOON_STYLE_BALLOON_ON              = &H1
%BALLOON_STYLE_SIZETOTEXT              = &H2
%BALLOON_STYLE_AUTOHIDE                = &H4
%BALLOON_STYLE_AUTOPACE                = &H8

%AUDIO_STATUS_AVAILABLE                = 0
%AUDIO_STATUS_NOAUDIO                  = 1
%AUDIO_STATUS_CANTOPENAUDIO            = 2
%AUDIO_STATUS_USERSPEAKING             = 3
%AUDIO_STATUS_CHARACTERSPEAKING        = 4
%AUDIO_STATUS_SROVERRIDEABLE           = 5
%AUDIO_STATUS_ERROR                    = 6

%LISTEN_STATUS_CANLISTEN               = 0
%LISTEN_STATUS_NOAUDIO                 = 1
%LISTEN_STATUS_NOTACTIVE               = 2
%LISTEN_STATUS_CANTOPENAUDIO           = 3
%LISTEN_STATUS_COULDNTINITIALIZESPEECH = 4
%LISTEN_STATUS_SPEECHDISABLED          = 5
%LISTEN_STATUS_ERROR                   = 6

%MK_ICON                               = &H1000

%LSCOMPLETE_CAUSE_PROGRAMDISABLED      = 1
%LSCOMPLETE_CAUSE_PROGRAMTIMEDOUT      = 2
%LSCOMPLETE_CAUSE_USERTIMEDOUT         = 3
%LSCOMPLETE_CAUSE_USERRELEASEDKEY      = 4
%LSCOMPLETE_CAUSE_USERUTTERANCEENDED   = 5
%LSCOMPLETE_CAUSE_CLIENTDEACTIVATED    = 6
%LSCOMPLETE_CAUSE_DEFAULTCHARCHANGE    = 7
%LSCOMPLETE_CAUSE_USERDISABLED         = 8


' ########################################################################################
' Interface name = IAgentUserInput
' IID = {A7B93C80-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentUserInput_INTERFACE_DEFINED)
    %IAgentUserInput_INTERFACE_DEFINED = 1

INTERFACE IAgentUserInput $IID_IAgentUserInput

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetCount <1610743808> ( _                     ' VTable offset = 28
     BYREF pdwCount AS LONG _                           ' __out long *pdwCount
   )                                                    ' void
   ' =====================================================================================
   METHOD GetItemID <1610743809> ( _                    ' VTable offset = 32
     BYVAL dwItemIndex AS LONG _                        ' __in long dwItemIndex
   , BYREF pdwCommandID AS LONG _                       ' __out long *pdwCommandID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetItemConfidence <1610743810> ( _            ' VTable offset = 36
     BYVAL dwItemIndex AS LONG _                        ' __in long dwItemIndex
   , BYREF plConfidence AS LONG _                       ' __out long *plConfidence
   )                                                    ' void
   ' =====================================================================================
   METHOD GetItemText <1610743811> ( _                  ' VTable offset = 40
     BYVAL dwItemIndex AS LONG _                        ' __in long dwItemIndex
   , BYREF pbszText AS WSTRING _                        ' __out BSTR *pbszText
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAllItemData <1610743812> ( _               ' VTable offset = 44
     BYREF pdwItemIndices AS VARIANT _                  ' __out VARIANT *pdwItemIndices
   , BYREF plConfidences AS VARIANT _                   ' __out VARIANT *plConfidences
   , BYREF pbszText AS VARIANT _                        ' __out VARIANT *pbszText
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentUserInput_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCommand
' IID = {A7B93C83-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCommand_INTERFACE_DEFINED)
    %IAgentCommand_INTERFACE_DEFINED = 1

INTERFACE IAgentCommand $IID_IAgentCommand

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetCaption <1610743808> ( _                   ' VTable offset = 28
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCaption <1610743809> ( _                   ' VTable offset = 32
     BYREF pbszCaption AS WSTRING _                     ' __out BSTR *pbszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVoice <1610743810> ( _                     ' VTable offset = 36
     BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVoice <1610743811> ( _                     ' VTable offset = 40
     BYREF pbszVoice AS WSTRING _                       ' __out BSTR *pbszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEnabled <1610743812> ( _                   ' VTable offset = 44
     BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEnabled <1610743813> ( _                   ' VTable offset = 48
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVisible <1610743814> ( _                   ' VTable offset = 52
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisible <1610743815> ( _                   ' VTable offset = 56
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConfidenceThreshold <1610743816> ( _       ' VTable offset = 60
     BYVAL lThreshold AS LONG _                         ' __in long lThreshold
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConfidenceThreshold <1610743817> ( _       ' VTable offset = 64
     BYREF plThreshold AS LONG _                        ' __out long *plThreshold
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConfidenceText <1610743818> ( _            ' VTable offset = 68
     BYVAL bszTipText AS WSTRING _                      ' __in BSTR bszTipText
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConfidenceText <1610743819> ( _            ' VTable offset = 72
     BYREF pbszTipText AS WSTRING _                     ' __out BSTR *pbszTipText
   )                                                    ' void
   ' =====================================================================================
   METHOD GetID <1610743820> ( _                        ' VTable offset = 76
     BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCommandEx
' IID = {B0913412-3B44-11D1-ACBA-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCommand
' ########################################################################################

#IF NOT %DEF(%IAgentCommandEx_INTERFACE_DEFINED)
    %IAgentCommandEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCommandEx $IID_IAgentCommandEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCommand Methods
   ' =====================================================================================
   METHOD SetCaption <1610743808> ( _                   ' VTable offset = 28
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCaption <1610743809> ( _                   ' VTable offset = 32
     BYREF pbszCaption AS WSTRING _                     ' __out BSTR *pbszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVoice <1610743810> ( _                     ' VTable offset = 36
     BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVoice <1610743811> ( _                     ' VTable offset = 40
     BYREF pbszVoice AS WSTRING _                       ' __out BSTR *pbszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEnabled <1610743812> ( _                   ' VTable offset = 44
     BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEnabled <1610743813> ( _                   ' VTable offset = 48
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVisible <1610743814> ( _                   ' VTable offset = 52
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisible <1610743815> ( _                   ' VTable offset = 56
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConfidenceThreshold <1610743816> ( _       ' VTable offset = 60
     BYVAL lThreshold AS LONG _                         ' __in long lThreshold
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConfidenceThreshold <1610743817> ( _       ' VTable offset = 64
     BYREF plThreshold AS LONG _                        ' __out long *plThreshold
   )                                                    ' void
   ' =====================================================================================
   METHOD SetConfidenceText <1610743818> ( _            ' VTable offset = 68
     BYVAL bszTipText AS WSTRING _                      ' __in BSTR bszTipText
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConfidenceText <1610743819> ( _            ' VTable offset = 72
     BYREF pbszTipText AS WSTRING _                     ' __out BSTR *pbszTipText
   )                                                    ' void
   ' =====================================================================================
   METHOD GetID <1610743820> ( _                        ' VTable offset = 76
     BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCommandEx Methods
   ' =====================================================================================
   METHOD SetHelpContextID <1610809344> ( _             ' VTable offset = 80
     BYVAL ulID AS LONG _                               ' __in long ulID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHelpContextID <1610809345> ( _             ' VTable offset = 84
     BYREF pulID AS LONG _                              ' __out long *pulID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVoiceCaption <1610809346> ( _              ' VTable offset = 88
     BYVAL bszVoiceCaption AS WSTRING _                 ' __in BSTR bszVoiceCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVoiceCaption <1610809347> ( _              ' VTable offset = 92
     BYREF pbszVoiceCaption AS WSTRING _                ' __out BSTR *pbszVoiceCaption
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCommandEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCommands
' IID = {A7B93C85-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCommands_INTERFACE_DEFINED)
    %IAgentCommands_INTERFACE_DEFINED = 1

INTERFACE IAgentCommands $IID_IAgentCommands

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetCommand <1610743808> ( _                   ' VTable offset = 28
     BYVAL dwCommandID AS LONG _                        ' __in long dwCommandID
   , BYREF ppunkCommand AS IUnknown _                   ' __out IUnknown **ppunkCommand
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCount <1610743809> ( _                     ' VTable offset = 32
     BYREF pdwCount AS LONG _                           ' __out long *pdwCount
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCaption <1610743810> ( _                   ' VTable offset = 36
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCaption <1610743811> ( _                   ' VTable offset = 40
     BYREF pbszCaption AS WSTRING _                     ' __out BSTR *pbszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVoice <1610743812> ( _                     ' VTable offset = 44
     BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVoice <1610743813> ( _                     ' VTable offset = 48
     BYREF pbszVoice AS WSTRING _                       ' __out BSTR *pbszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVisible <1610743814> ( _                   ' VTable offset = 52
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisible <1610743815> ( _                   ' VTable offset = 56
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <1610743816> ( _                          ' VTable offset = 60
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   , BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================
   METHOD Insert <1610743817> ( _                       ' VTable offset = 64
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   , BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYVAL dwRefID AS LONG _                            ' __in long dwRefID
   , BYVAL bBefore AS LONG _                            ' __in long bBefore
   , BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743818> ( _                       ' VTable offset = 68
     BYVAL dwID AS LONG _                               ' __in long dwID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <1610743819> ( _                    ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCommands_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCommandsEx
' IID = {6BA90C00-3910-11D1-ACB3-00C04FD97575}
' IAgentCommandsEx Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCommands
' ########################################################################################

#IF NOT %DEF(%IAgentCommandsEx_INTERFACE_DEFINED)
    %IAgentCommandsEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCommandsEx $IID_IAgentCommandsEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCommands Methods
   ' =====================================================================================
   METHOD GetCommand <1610743808> ( _                   ' VTable offset = 28
     BYVAL dwCommandID AS LONG _                        ' __in long dwCommandID
   , BYREF ppunkCommand AS IUnknown _                   ' __out IUnknown **ppunkCommand
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCount <1610743809> ( _                     ' VTable offset = 32
     BYREF pdwCount AS LONG _                           ' __out long *pdwCount
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCaption <1610743810> ( _                   ' VTable offset = 36
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCaption <1610743811> ( _                   ' VTable offset = 40
     BYREF pbszCaption AS WSTRING _                     ' __out BSTR *pbszCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVoice <1610743812> ( _                     ' VTable offset = 44
     BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVoice <1610743813> ( _                     ' VTable offset = 48
     BYREF pbszVoice AS WSTRING _                       ' __out BSTR *pbszVoice
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVisible <1610743814> ( _                   ' VTable offset = 52
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisible <1610743815> ( _                   ' VTable offset = 56
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <1610743816> ( _                          ' VTable offset = 60
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   , BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================
   METHOD Insert <1610743817> ( _                       ' VTable offset = 64
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   , BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYVAL dwRefID AS LONG _                            ' __in long dwRefID
   , BYVAL bBefore AS LONG _                            ' __in long bBefore
   , BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743818> ( _                       ' VTable offset = 68
     BYVAL dwID AS LONG _                               ' __in long dwID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <1610743819> ( _                    ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCommandsEx Methods
   ' =====================================================================================
   METHOD GetCommandEx <1610809344> ( _                 ' VTable offset = 76
     BYVAL dwCommandID AS LONG _                        ' __in long dwCommandID
   , BYREF ppCommandEx AS IAgentCommandEx _             ' __out IAgentCommandEx **ppCommandEx
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultID <1610809345> ( _                 ' VTable offset = 80
     BYVAL dwID AS LONG _                               ' __in long dwID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDefaultID <1610809346> ( _                 ' VTable offset = 84
     BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetHelpContextID <1610809347> ( _             ' VTable offset = 88
     BYVAL ulHelpID AS LONG _                           ' __in long ulHelpID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHelpContextID <1610809348> ( _             ' VTable offset = 92
     BYREF pulHelpID AS LONG _                          ' __out long *pulHelpID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontName <1610809349> ( _                  ' VTable offset = 96
     BYVAL bszFontName AS WSTRING _                     ' __in BSTR bszFontName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontName <1610809350> ( _                  ' VTable offset = 100
     BYREF pbszFontName AS WSTRING _                    ' __out BSTR *pbszFontName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontSize <1610809351> ( _                  ' VTable offset = 104
     BYVAL lFontSize AS LONG _                          ' __in long lFontSize
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontSize <1610809352> ( _                  ' VTable offset = 108
     BYREF lFontSize AS LONG _                          ' __out long *lFontSize
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVoiceCaption <1610809353> ( _              ' VTable offset = 112
     BYVAL bszVoiceCaption AS WSTRING _                 ' __in BSTR bszVoiceCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVoiceCaption <1610809354> ( _              ' VTable offset = 116
     BYREF bszVoiceCaption AS WSTRING _                 ' __out BSTR *bszVoiceCaption
   )                                                    ' void
   ' =====================================================================================
   METHOD AddEx <1610809355> ( _                        ' VTable offset = 120
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   , BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   , BYVAL bszVoiceCaption AS WSTRING _                 ' __in BSTR bszVoiceCaption
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYVAL ulHelpId AS LONG _                           ' __in long ulHelpId
   , BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertEx <1610809356> ( _                     ' VTable offset = 124
     BYVAL bszCaption AS WSTRING _                      ' __in BSTR bszCaption
   , BYVAL bszVoice AS WSTRING _                        ' __in BSTR bszVoice
   , BYVAL bszVoiceCaption AS WSTRING _                 ' __in BSTR bszVoiceCaption
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYVAL ulHelpId AS LONG _                           ' __in long ulHelpId
   , BYVAL dwRefID AS LONG _                            ' __in long dwRefID
   , BYVAL bBefore AS LONG _                            ' __in long bBefore
   , BYREF pdwID AS LONG _                              ' __out long *pdwID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGlobalVoiceCommandsEnabled <1610809357> ( _ ' VTable offset = 128
     BYVAL bEnable AS LONG _                            ' __in long bEnable
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGlobalVoiceCommandsEnabled <1610809358> ( _ ' VTable offset = 132
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCommandsEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCommandWindow
' IID = {6D0ECB23-9968-11D0-AC6E-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCommandWindow_INTERFACE_DEFINED)
    %IAgentCommandWindow_INTERFACE_DEFINED = 1

INTERFACE IAgentCommandWindow $IID_IAgentCommandWindow

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetVisible <1610743808> ( _                   ' VTable offset = 28
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisible <1610743809> ( _                   ' VTable offset = 32
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPosition <1610743810> ( _                  ' VTable offset = 36
     BYREF plLeft AS LONG _                             ' __out long *plLeft
   , BYREF plTop AS LONG _                              ' __out long *plTop
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize <1610743811> ( _                      ' VTable offset = 40
     BYREF plWidth AS LONG _                            ' __out long *plWidth
   , BYREF plHeight AS LONG _                           ' __out long *plHeight
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCommandWindow_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentSpeechInputProperties
' IID = {A7B93C87-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentSpeechInputProperties_INTERFACE_DEFINED)
    %IAgentSpeechInputProperties_INTERFACE_DEFINED = 1

INTERFACE IAgentSpeechInputProperties $IID_IAgentSpeechInputProperties

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetInstalled <1610743808> ( _                 ' VTable offset = 28
     BYREF pbInstalled AS LONG _                        ' __out long *pbInstalled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEnabled <1610743809> ( _                   ' VTable offset = 32
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHotKey <1610743810> ( _                    ' VTable offset = 36
     BYREF pbszHotCharKey AS WSTRING _                  ' __out BSTR *pbszHotCharKey
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLCID <1610743811> ( _                      ' VTable offset = 40
     BYREF plcidCurrent AS DWORD _                      ' __out LCID *plcidCurrent
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEngine <1610743812> ( _                    ' VTable offset = 44
     BYREF pbszEngine AS WSTRING _                      ' __out BSTR *pbszEngine
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEngine <1610743813> ( _                    ' VTable offset = 48
     BYVAL bszEngine AS WSTRING _                       ' __in BSTR bszEngine
   )                                                    ' void
   ' =====================================================================================
   METHOD GetListeningTip <1610743814> ( _              ' VTable offset = 52
     BYREF pbListeningTip AS LONG _                     ' __out long *pbListeningTip
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentSpeechInputProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentAudioOutputProperties
' IID = {A7B93C89-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentAudioOutputProperties_INTERFACE_DEFINED)
    %IAgentAudioOutputProperties_INTERFACE_DEFINED = 1

INTERFACE IAgentAudioOutputProperties $IID_IAgentAudioOutputProperties

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetEnabled <1610743808> ( _                   ' VTable offset = 28
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUsingSoundEffects <1610743809> ( _         ' VTable offset = 32
     BYREF pbUsingSoundEffects AS LONG _                ' __out long *pbUsingSoundEffects
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentAudioOutputProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentAudioOutputPropertiesEx
' IID = {A7B93CA0-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentAudioOutputProperties
' ########################################################################################

#IF NOT %DEF(%IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED)
    %IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED = 1

INTERFACE IAgentAudioOutputPropertiesEx $IID_IAgentAudioOutputPropertiesEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentAudioOutputProperties Methods
   ' =====================================================================================
   METHOD GetEnabled <1610743808> ( _                   ' VTable offset = 28
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUsingSoundEffects <1610743809> ( _         ' VTable offset = 32
     BYREF pbUsingSoundEffects AS LONG _                ' __out long *pbUsingSoundEffects
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentAudioOutputPropertiesEx Methods
   ' =====================================================================================
   METHOD GetStatus <1610809344> ( _                    ' VTable offset = 36
     BYREF plStatus AS LONG _                           ' __out long *plStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentAudioOutputPropertiesEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentPropertySheet
' IID = {A7B93C8B-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentPropertySheet_INTERFACE_DEFINED)
    %IAgentPropertySheet_INTERFACE_DEFINED = 1

INTERFACE IAgentPropertySheet $IID_IAgentPropertySheet

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetVisible <1610743808> ( _                   ' VTable offset = 28
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVisible <1610743809> ( _                   ' VTable offset = 32
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPosition <1610743810> ( _                  ' VTable offset = 36
     BYREF plLeft AS LONG _                             ' __out long *plLeft
   , BYREF plTop AS LONG _                              ' __out long *plTop
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize <1610743811> ( _                      ' VTable offset = 40
     BYREF plWidth AS LONG _                            ' __out long *plWidth
   , BYREF plHeight AS LONG _                           ' __out long *plHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPage <1610743812> ( _                      ' VTable offset = 44
     BYREF pbszPage AS WSTRING _                        ' __out BSTR *pbszPage
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPage <1610743813> ( _                      ' VTable offset = 48
     BYVAL bszPage AS WSTRING _                         ' __in BSTR bszPage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentPropertySheet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentBalloon
' IID = {A7B93C8D-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentBalloon_INTERFACE_DEFINED)
    %IAgentBalloon_INTERFACE_DEFINED = 1

INTERFACE IAgentBalloon $IID_IAgentBalloon

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetEnabled <1610743808> ( _                   ' VTable offset = 28
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNumLines <1610743809> ( _                  ' VTable offset = 32
     BYREF plLines AS LONG _                            ' __out long *plLines
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNumCharsPerLine <1610743810> ( _           ' VTable offset = 36
     BYREF plCharsPerLine AS LONG _                     ' __out long *plCharsPerLine
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontName <1610743811> ( _                  ' VTable offset = 40
     BYREF pbszFontName AS WSTRING _                    ' __out BSTR *pbszFontName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontSize <1610743812> ( _                  ' VTable offset = 44
     BYREF plFontSize AS LONG _                         ' __out long *plFontSize
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontBold <1610743813> ( _                  ' VTable offset = 48
     BYREF pbFontBold AS LONG _                         ' __out long *pbFontBold
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontItalic <1610743814> ( _                ' VTable offset = 52
     BYREF pbFontItalic AS LONG _                       ' __out long *pbFontItalic
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontStrikethru <1610743815> ( _            ' VTable offset = 56
     BYREF pbFontStrikethru AS LONG _                   ' __out long *pbFontStrikethru
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontUnderline <1610743816> ( _             ' VTable offset = 60
     BYREF pbFontUnderline AS LONG _                    ' __out long *pbFontUnderline
   )                                                    ' void
   ' =====================================================================================
   METHOD GetForeColor <1610743817> ( _                 ' VTable offset = 64
     BYREF plFGColor AS LONG _                          ' __out long *plFGColor
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBackColor <1610743818> ( _                 ' VTable offset = 68
     BYREF plBGColor AS LONG _                          ' __out long *plBGColor
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBorderColor <1610743819> ( _               ' VTable offset = 72
     BYREF plBorderColor AS LONG _                      ' __out long *plBorderColor
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVisible <1610743820> ( _                   ' VTable offset = 76
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisible <1610743821> ( _                   ' VTable offset = 80
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontName <1610743822> ( _                  ' VTable offset = 84
     BYVAL bszFontName AS WSTRING _                     ' __in BSTR bszFontName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontSize <1610743823> ( _                  ' VTable offset = 88
     BYVAL lFontSize AS LONG _                          ' __in long lFontSize
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontCharSet <1610743824> ( _               ' VTable offset = 92
     BYVAL sFontCharSet AS INTEGER _                    ' __in short sFontCharSet
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontCharSet <1610743825> ( _               ' VTable offset = 96
     BYREF psFontCharSet AS INTEGER _                   ' __out short *psFontCharSet
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentBalloon_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentBalloonEx
' IID = {D7A6D440-8872-11D1-9EC6-00C04FD7081F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentBalloon
' ########################################################################################

#IF NOT %DEF(%IAgentBalloonEx_INTERFACE_DEFINED)
    %IAgentBalloonEx_INTERFACE_DEFINED = 1

INTERFACE IAgentBalloonEx $IID_IAgentBalloonEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentBalloon Methods
   ' =====================================================================================
   METHOD GetEnabled <1610743808> ( _                   ' VTable offset = 28
     BYREF pbEnabled AS LONG _                          ' __out long *pbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNumLines <1610743809> ( _                  ' VTable offset = 32
     BYREF plLines AS LONG _                            ' __out long *plLines
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNumCharsPerLine <1610743810> ( _           ' VTable offset = 36
     BYREF plCharsPerLine AS LONG _                     ' __out long *plCharsPerLine
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontName <1610743811> ( _                  ' VTable offset = 40
     BYREF pbszFontName AS WSTRING _                    ' __out BSTR *pbszFontName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontSize <1610743812> ( _                  ' VTable offset = 44
     BYREF plFontSize AS LONG _                         ' __out long *plFontSize
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontBold <1610743813> ( _                  ' VTable offset = 48
     BYREF pbFontBold AS LONG _                         ' __out long *pbFontBold
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontItalic <1610743814> ( _                ' VTable offset = 52
     BYREF pbFontItalic AS LONG _                       ' __out long *pbFontItalic
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontStrikethru <1610743815> ( _            ' VTable offset = 56
     BYREF pbFontStrikethru AS LONG _                   ' __out long *pbFontStrikethru
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontUnderline <1610743816> ( _             ' VTable offset = 60
     BYREF pbFontUnderline AS LONG _                    ' __out long *pbFontUnderline
   )                                                    ' void
   ' =====================================================================================
   METHOD GetForeColor <1610743817> ( _                 ' VTable offset = 64
     BYREF plFGColor AS LONG _                          ' __out long *plFGColor
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBackColor <1610743818> ( _                 ' VTable offset = 68
     BYREF plBGColor AS LONG _                          ' __out long *plBGColor
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBorderColor <1610743819> ( _               ' VTable offset = 72
     BYREF plBorderColor AS LONG _                      ' __out long *plBorderColor
   )                                                    ' void
   ' =====================================================================================
   METHOD SetVisible <1610743820> ( _                   ' VTable offset = 76
     BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisible <1610743821> ( _                   ' VTable offset = 80
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontName <1610743822> ( _                  ' VTable offset = 84
     BYVAL bszFontName AS WSTRING _                     ' __in BSTR bszFontName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontSize <1610743823> ( _                  ' VTable offset = 88
     BYVAL lFontSize AS LONG _                          ' __in long lFontSize
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFontCharSet <1610743824> ( _               ' VTable offset = 92
     BYVAL sFontCharSet AS INTEGER _                    ' __in short sFontCharSet
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFontCharSet <1610743825> ( _               ' VTable offset = 96
     BYREF psFontCharSet AS INTEGER _                   ' __out short *psFontCharSet
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentBalloonEx Methods
   ' =====================================================================================
   METHOD SetStyle ( _                                  ' VTable offset = 100
     BYVAL lStyle AS LONG _                             ' __in long lStyle
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStyle ( _                                  ' VTable offset = 104
     BYREF plStyle AS LONG _                            ' __out long *plStyle
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNumLines ( _                               ' VTable offset = 108
     BYVAL lLines AS LONG _                             ' __in long lLines
   )                                                    ' void
   ' =====================================================================================
   METHOD SetNumCharsPerLine ( _                        ' VTable offset = 112
     BYVAL lCharsPerLine AS LONG _                      ' __in long lCharsPerLine
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentBalloonEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCharacter
' IID = {A7B93C8F-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCharacter_INTERFACE_DEFINED)
    %IAgentCharacter_INTERFACE_DEFINED = 1

INTERFACE IAgentCharacter $IID_IAgentCharacter

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetVisible <1610743808> ( _                   ' VTable offset = 28
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPosition <1610743809> ( _                  ' VTable offset = 32
     BYVAL lLeft AS LONG _                              ' __in long lLeft
   , BYVAL lTop AS LONG _                               ' __in long lTop
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPosition <1610743810> ( _                  ' VTable offset = 36
     BYREF plLeft AS LONG _                             ' __out long *plLeft
   , BYREF plTop AS LONG _                              ' __out long *plTop
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSize <1610743811> ( _                      ' VTable offset = 40
     BYVAL lWidth AS LONG _                             ' __in long lWidth
   , BYVAL lHeight AS LONG _                            ' __in long lHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize <1610743812> ( _                      ' VTable offset = 44
     BYREF plWidth AS LONG _                            ' __out long *plWidth
   , BYREF plHeight AS LONG _                           ' __out long *plHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName <1610743813> ( _                      ' VTable offset = 48
     BYREF pbszName AS WSTRING _                        ' __out BSTR *pbszName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDescription <1610743814> ( _               ' VTable offset = 52
     BYREF pbszDescription AS WSTRING _                 ' __out BSTR *pbszDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTTSSpeed <1610743815> ( _                  ' VTable offset = 56
     BYREF pdwSpeed AS LONG _                           ' __out long *pdwSpeed
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTTSPitch <1610743816> ( _                  ' VTable offset = 60
     BYREF pwPitch AS INTEGER _                         ' __out short *pwPitch
   )                                                    ' void
   ' =====================================================================================
   METHOD Activate <1610743817> ( _                     ' VTable offset = 64
     BYVAL sState AS INTEGER _                          ' __in short sState
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIdleOn <1610743818> ( _                    ' VTable offset = 68
     BYVAL bOn AS LONG _                                ' __in long bOn
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIdleOn <1610743819> ( _                    ' VTable offset = 72
     BYREF pbOn AS LONG _                               ' __out long *pbOn
   )                                                    ' void
   ' =====================================================================================
   METHOD Prepare <1610743820> ( _                      ' VTable offset = 76
     BYVAL dwType AS LONG _                             ' __in long dwType
   , BYVAL bszName AS WSTRING _                         ' __in BSTR bszName
   , BYVAL bQueue AS LONG _                             ' __in long bQueue
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <1610743821> ( _                         ' VTable offset = 80
     BYVAL bszAnimation AS WSTRING _                    ' __in BSTR bszAnimation
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <1610743822> ( _                         ' VTable offset = 84
     BYVAL dwReqID AS LONG _                            ' __in long dwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD StopAll <1610743823> ( _                      ' VTable offset = 88
     BYVAL lTypes AS LONG _                             ' __in long lTypes
   )                                                    ' void
   ' =====================================================================================
   METHOD Wait <1610743824> ( _                         ' VTable offset = 92
     BYVAL dwReqID AS LONG _                            ' __in long dwReqID
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Interrupt <1610743825> ( _                    ' VTable offset = 96
     BYVAL dwReqID AS LONG _                            ' __in long dwReqID
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Show <1610743826> ( _                         ' VTable offset = 100
     BYVAL bFast AS LONG _                              ' __in long bFast
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Hide <1610743827> ( _                         ' VTable offset = 104
     BYVAL bFast AS LONG _                              ' __in long bFast
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Speak <1610743828> ( _                        ' VTable offset = 108
     BYVAL bszText AS WSTRING _                         ' __in BSTR bszText
   , BYVAL bszUrl AS WSTRING _                          ' __in BSTR bszUrl
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveTo <1610743829> ( _                       ' VTable offset = 112
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   , BYVAL lSpeed AS LONG _                             ' __in long lSpeed
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD GestureAt <1610743830> ( _                    ' VTable offset = 116
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMoveCause <1610743831> ( _                 ' VTable offset = 120
     BYREF pdwCause AS LONG _                           ' __out long *pdwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisibilityCause <1610743832> ( _           ' VTable offset = 124
     BYREF pdwCause AS LONG _                           ' __out long *pdwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD HasOtherClients <1610743833> ( _              ' VTable offset = 128
     BYREF plNumOtherClients AS LONG _                  ' __out long *plNumOtherClients
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSoundEffectsOn <1610743834> ( _            ' VTable offset = 132
     BYVAL bOn AS LONG _                                ' __in long bOn
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSoundEffectsOn <1610743835> ( _            ' VTable offset = 136
     BYREF pbOn AS LONG _                               ' __out long *pbOn
   )                                                    ' void
   ' =====================================================================================
   METHOD SetName <1610743836> ( _                      ' VTable offset = 140
     BYVAL bszName AS WSTRING _                         ' __in BSTR bszName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDescription <1610743837> ( _               ' VTable offset = 144
     BYVAL bszDescription AS WSTRING _                  ' __in BSTR bszDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD GetExtraData <1610743838> ( _                 ' VTable offset = 148
     BYREF pbszExtraData AS WSTRING _                   ' __out BSTR *pbszExtraData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCharacter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCharacterEx
' IID = {98BBE491-2EED-11D1-ACAC-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCharacter
' ########################################################################################

#IF NOT %DEF(%IAgentCharacterEx_INTERFACE_DEFINED)
    %IAgentCharacterEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCharacterEx $IID_IAgentCharacterEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCharacter Methods
   ' =====================================================================================
   METHOD GetVisible <1610743808> ( _                   ' VTable offset = 28
     BYREF pbVisible AS LONG _                          ' __out long *pbVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPosition <1610743809> ( _                  ' VTable offset = 32
     BYVAL lLeft AS LONG _                              ' __in long lLeft
   , BYVAL lTop AS LONG _                               ' __in long lTop
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPosition <1610743810> ( _                  ' VTable offset = 36
     BYREF plLeft AS LONG _                             ' __out long *plLeft
   , BYREF plTop AS LONG _                              ' __out long *plTop
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSize <1610743811> ( _                      ' VTable offset = 40
     BYVAL lWidth AS LONG _                             ' __in long lWidth
   , BYVAL lHeight AS LONG _                            ' __in long lHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize <1610743812> ( _                      ' VTable offset = 44
     BYREF plWidth AS LONG _                            ' __out long *plWidth
   , BYREF plHeight AS LONG _                           ' __out long *plHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName <1610743813> ( _                      ' VTable offset = 48
     BYREF pbszName AS WSTRING _                        ' __out BSTR *pbszName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDescription <1610743814> ( _               ' VTable offset = 52
     BYREF pbszDescription AS WSTRING _                 ' __out BSTR *pbszDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTTSSpeed <1610743815> ( _                  ' VTable offset = 56
     BYREF pdwSpeed AS LONG _                           ' __out long *pdwSpeed
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTTSPitch <1610743816> ( _                  ' VTable offset = 60
     BYREF pwPitch AS INTEGER _                         ' __out short *pwPitch
   )                                                    ' void
   ' =====================================================================================
   METHOD Activate <1610743817> ( _                     ' VTable offset = 64
     BYVAL sState AS INTEGER _                          ' __in short sState
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIdleOn <1610743818> ( _                    ' VTable offset = 68
     BYVAL bOn AS LONG _                                ' __in long bOn
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIdleOn <1610743819> ( _                    ' VTable offset = 72
     BYREF pbOn AS LONG _                               ' __out long *pbOn
   )                                                    ' void
   ' =====================================================================================
   METHOD Prepare <1610743820> ( _                      ' VTable offset = 76
     BYVAL dwType AS LONG _                             ' __in long dwType
   , BYVAL bszName AS WSTRING _                         ' __in BSTR bszName
   , BYVAL bQueue AS LONG _                             ' __in long bQueue
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <1610743821> ( _                         ' VTable offset = 80
     BYVAL bszAnimation AS WSTRING _                    ' __in BSTR bszAnimation
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <1610743822> ( _                         ' VTable offset = 84
     BYVAL dwReqID AS LONG _                            ' __in long dwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD StopAll <1610743823> ( _                      ' VTable offset = 88
     BYVAL lTypes AS LONG _                             ' __in long lTypes
   )                                                    ' void
   ' =====================================================================================
   METHOD Wait <1610743824> ( _                         ' VTable offset = 92
     BYVAL dwReqID AS LONG _                            ' __in long dwReqID
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Interrupt <1610743825> ( _                    ' VTable offset = 96
     BYVAL dwReqID AS LONG _                            ' __in long dwReqID
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Show <1610743826> ( _                         ' VTable offset = 100
     BYVAL bFast AS LONG _                              ' __in long bFast
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Hide <1610743827> ( _                         ' VTable offset = 104
     BYVAL bFast AS LONG _                              ' __in long bFast
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Speak <1610743828> ( _                        ' VTable offset = 108
     BYVAL bszText AS WSTRING _                         ' __in BSTR bszText
   , BYVAL bszUrl AS WSTRING _                          ' __in BSTR bszUrl
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveTo <1610743829> ( _                       ' VTable offset = 112
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   , BYVAL lSpeed AS LONG _                             ' __in long lSpeed
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD GestureAt <1610743830> ( _                    ' VTable offset = 116
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMoveCause <1610743831> ( _                 ' VTable offset = 120
     BYREF pdwCause AS LONG _                           ' __out long *pdwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisibilityCause <1610743832> ( _           ' VTable offset = 124
     BYREF pdwCause AS LONG _                           ' __out long *pdwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD HasOtherClients <1610743833> ( _              ' VTable offset = 128
     BYREF plNumOtherClients AS LONG _                  ' __out long *plNumOtherClients
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSoundEffectsOn <1610743834> ( _            ' VTable offset = 132
     BYVAL bOn AS LONG _                                ' __in long bOn
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSoundEffectsOn <1610743835> ( _            ' VTable offset = 136
     BYREF pbOn AS LONG _                               ' __out long *pbOn
   )                                                    ' void
   ' =====================================================================================
   METHOD SetName <1610743836> ( _                      ' VTable offset = 140
     BYVAL bszName AS WSTRING _                         ' __in BSTR bszName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDescription <1610743837> ( _               ' VTable offset = 144
     BYVAL bszDescription AS WSTRING _                  ' __in BSTR bszDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD GetExtraData <1610743838> ( _                 ' VTable offset = 148
     BYREF pbszExtraData AS WSTRING _                   ' __out BSTR *pbszExtraData
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCharacterEx Methods
   ' =====================================================================================
   METHOD ShowPopupMenu <1610809344> ( _                ' VTable offset = 152
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAutoPopupMenu <1610809345> ( _             ' VTable offset = 156
     BYVAL bAutoPopupMenu AS LONG _                     ' __in long bAutoPopupMenu
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAutoPopupMenu <1610809346> ( _             ' VTable offset = 160
     BYREF pbAutoPopupMenu AS LONG _                    ' __out long *pbAutoPopupMenu
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHelpFileName <1610809347> ( _              ' VTable offset = 164
     BYREF pbszName AS WSTRING _                        ' __out BSTR *pbszName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetHelpFileName <1610809348> ( _              ' VTable offset = 168
     BYVAL bszName AS WSTRING _                         ' __in BSTR bszName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetHelpModeOn <1610809349> ( _                ' VTable offset = 172
     BYVAL bHelpModeOn AS LONG _                        ' __in long bHelpModeOn
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHelpModeOn <1610809350> ( _                ' VTable offset = 176
     BYREF pbHelpModeOn AS LONG _                       ' __out long *pbHelpModeOn
   )                                                    ' void
   ' =====================================================================================
   METHOD SetHelpContextID <1610809351> ( _             ' VTable offset = 180
     BYVAL ulID AS LONG _                               ' __in long ulID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHelpContextID <1610809352> ( _             ' VTable offset = 184
     BYREF pulID AS LONG _                              ' __out long *pulID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetActive <1610809353> ( _                    ' VTable offset = 188
     BYREF psState AS INTEGER _                         ' __out short *psState
   )                                                    ' void
   ' =====================================================================================
   METHOD Listen <1610809354> ( _                       ' VTable offset = 192
     BYVAL bListen AS LONG _                            ' __in long bListen
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLanguageID <1610809355> ( _                ' VTable offset = 196
     BYVAL langid AS LONG _                             ' __in long langid
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLanguageID <1610809356> ( _                ' VTable offset = 200
     BYREF plangid AS LONG _                            ' __out long *plangid
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTTSModeID <1610809357> ( _                 ' VTable offset = 204
     BYREF pbszModeID AS WSTRING _                      ' __out BSTR *pbszModeID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTTSModeID <1610809358> ( _                 ' VTable offset = 208
     BYVAL bszModeID AS WSTRING _                       ' __in BSTR bszModeID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSRModeID <1610809359> ( _                  ' VTable offset = 212
     BYREF pbszModeID AS WSTRING _                      ' __out BSTR *pbszModeID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSRModeID <1610809360> ( _                  ' VTable offset = 216
     BYVAL bszModeID AS WSTRING _                       ' __in BSTR bszModeID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGUID <1610809361> ( _                      ' VTable offset = 220
     BYREF pbszID AS WSTRING _                          ' __out BSTR *pbszID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetOriginalSize <1610809362> ( _              ' VTable offset = 224
     BYREF plWidth AS LONG _                            ' __out long *plWidth
   , BYREF plHeight AS LONG _                           ' __out long *plHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD Think <1610809363> ( _                        ' VTable offset = 228
     BYVAL bszText AS WSTRING _                         ' __in BSTR bszText
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVersion <1610809364> ( _                   ' VTable offset = 232
     BYREF psMajor AS INTEGER _                         ' __out short *psMajor
   , BYREF psMinor AS INTEGER _                         ' __out short *psMinor
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAnimationNames <1610809365> ( _            ' VTable offset = 236
     BYREF punkEnum AS IUnknown _                       ' __out IUnknown **punkEnum
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSRStatus <1610809366> ( _                  ' VTable offset = 240
     BYREF plStatus AS LONG _                           ' __out long *plStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCharacterEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgent
' IID = {A7B93C91-7B81-11D0-AC5F-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgent_INTERFACE_DEFINED)
    %IAgent_INTERFACE_DEFINED = 1

INTERFACE IAgent $IID_IAgent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Load <1610743808> ( _                         ' VTable offset = 28
     BYVAL vLoadKey AS VARIANT _                        ' __in VARIANT vLoadKey
   , BYREF pdwCharID AS LONG _                          ' __out long *pdwCharID
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Unload <1610743809> ( _                       ' VTable offset = 32
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   )                                                    ' void
   ' =====================================================================================
   METHOD Register <1610743810> ( _                     ' VTable offset = 36
     BYVAL punkNotifySink AS IUnknown _                 ' __in IUnknown *punkNotifySink
   , BYREF pdwSinkID AS LONG _                          ' __out long *pdwSinkID
   )                                                    ' void
   ' =====================================================================================
   METHOD Unregister <1610743811> ( _                   ' VTable offset = 40
     BYVAL dwSinkID AS LONG _                           ' __in long dwSinkID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCharacter <1610743812> ( _                 ' VTable offset = 44
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYREF ppunkCharacter AS IDispatch _                ' __out IDispatch **ppunkCharacter
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSuspended <1610743813> ( _                 ' VTable offset = 48
     BYREF pbSuspended AS LONG _                        ' __out long *pbSuspended
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentEx
' IID = {48D12BA0-5B77-11D1-9EC1-00C04FD7081F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgent
' ########################################################################################

#IF NOT %DEF(%IAgentEx_INTERFACE_DEFINED)
    %IAgentEx_INTERFACE_DEFINED = 1

INTERFACE IAgentEx $IID_IAgentEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgent Methods
   ' =====================================================================================
   METHOD Load <1610743808> ( _                         ' VTable offset = 28
     BYVAL vLoadKey AS VARIANT _                        ' __in VARIANT vLoadKey
   , BYREF pdwCharID AS LONG _                          ' __out long *pdwCharID
   , BYREF pdwReqID AS LONG _                           ' __out long *pdwReqID
   )                                                    ' void
   ' =====================================================================================
   METHOD Unload <1610743809> ( _                       ' VTable offset = 32
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   )                                                    ' void
   ' =====================================================================================
   METHOD Register <1610743810> ( _                     ' VTable offset = 36
     BYVAL punkNotifySink AS IUnknown _                 ' __in IUnknown *punkNotifySink
   , BYREF pdwSinkID AS LONG _                          ' __out long *pdwSinkID
   )                                                    ' void
   ' =====================================================================================
   METHOD Unregister <1610743811> ( _                   ' VTable offset = 40
     BYVAL dwSinkID AS LONG _                           ' __in long dwSinkID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCharacter <1610743812> ( _                 ' VTable offset = 44
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYREF ppunkCharacter AS IDispatch _                ' __out IDispatch **ppunkCharacter
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSuspended <1610743813> ( _                 ' VTable offset = 48
     BYREF pbSuspended AS LONG _                        ' __out long *pbSuspended
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentEx Methods
   ' =====================================================================================
   METHOD GetCharacterEx <1610809344> ( _               ' VTable offset = 52
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYREF ppCharacterEx AS IAgentCharacterEx _         ' __out IAgentCharacterEx **ppCharacterEx
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVersion <1610809345> ( _                   ' VTable offset = 56
     BYREF psMajor AS INTEGER _                         ' __out short *psMajor
   , BYREF psMinor AS INTEGER _                         ' __out short *psMinor
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowDefaultCharacterProperties <1610809346> ( _ ' VTable offset = 60
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   , BYVAL bUseDefaultPosition AS LONG _                ' __in long bUseDefaultPosition
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentNotifySink
' IID = {00D18159-8466-11D0-AC63-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentNotifySink_INTERFACE_DEFINED)
    %IAgentNotifySink_INTERFACE_DEFINED = 1

INTERFACE IAgentNotifySink $IID_IAgentNotifySink

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Command <1610743808> ( _                      ' VTable offset = 28
     BYVAL dwCommandID AS LONG _                        ' __in long dwCommandID
   , BYVAL punkUserInput AS IUnknown _                  ' __in IUnknown *punkUserInput
   )                                                    ' void
   ' =====================================================================================
   METHOD ActivateInputState <1610743809> ( _           ' VTable offset = 32
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bActivated AS LONG _                         ' __in long bActivated
   )                                                    ' void
   ' =====================================================================================
   METHOD Restart <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Shutdown <1610743811> ( _                     ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD VisibleState <1610743812> ( _                 ' VTable offset = 44
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYVAL dwCause AS LONG _                            ' __in long dwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD Click <1610743813> ( _                        ' VTable offset = 48
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD DblClick <1610743814> ( _                     ' VTable offset = 52
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD DragStart <1610743815> ( _                    ' VTable offset = 56
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD DragComplete <1610743816> ( _                 ' VTable offset = 60
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestStart <1610743817> ( _                 ' VTable offset = 64
     BYVAL dwRequestID AS LONG _                        ' __in long dwRequestID
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestComplete <1610743818> ( _              ' VTable offset = 68
     BYVAL dwRequestID AS LONG _                        ' __in long dwRequestID
   , BYVAL hrStatus AS LONG _                           ' __in long hrStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD BookMark <1610743819> ( _                     ' VTable offset = 72
     BYVAL dwBookMarkID AS LONG _                       ' __in long dwBookMarkID
   )                                                    ' void
   ' =====================================================================================
   METHOD Idle <1610743820> ( _                         ' VTable offset = 76
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bStart AS LONG _                             ' __in long bStart
   )                                                    ' void
   ' =====================================================================================
   METHOD Move <1610743821> ( _                         ' VTable offset = 80
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   , BYVAL dwCause AS LONG _                            ' __in long dwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD Size <1610743822> ( _                         ' VTable offset = 84
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL lWidth AS LONG _                             ' __in long lWidth
   , BYVAL lHeight AS LONG _                            ' __in long lHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD BalloonVisibleState <1610743823> ( _          ' VTable offset = 88
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentNotifySink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentNotifySinkEx
' IID = {08C75162-3C9C-11D1-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentNotifySink
' ########################################################################################

#IF NOT %DEF(%IAgentNotifySinkEx_INTERFACE_DEFINED)
    %IAgentNotifySinkEx_INTERFACE_DEFINED = 1

INTERFACE IAgentNotifySinkEx $IID_IAgentNotifySinkEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentNotifySink Methods
   ' =====================================================================================
   METHOD Command <1610743808> ( _                      ' VTable offset = 28
     BYVAL dwCommandID AS LONG _                        ' __in long dwCommandID
   , BYVAL punkUserInput AS IUnknown _                  ' __in IUnknown *punkUserInput
   )                                                    ' void
   ' =====================================================================================
   METHOD ActivateInputState <1610743809> ( _           ' VTable offset = 32
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bActivated AS LONG _                         ' __in long bActivated
   )                                                    ' void
   ' =====================================================================================
   METHOD Restart <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Shutdown <1610743811> ( _                     ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD VisibleState <1610743812> ( _                 ' VTable offset = 44
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   , BYVAL dwCause AS LONG _                            ' __in long dwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD Click <1610743813> ( _                        ' VTable offset = 48
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD DblClick <1610743814> ( _                     ' VTable offset = 52
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD DragStart <1610743815> ( _                    ' VTable offset = 56
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD DragComplete <1610743816> ( _                 ' VTable offset = 60
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL fwKeys AS INTEGER _                          ' __in short fwKeys
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestStart <1610743817> ( _                 ' VTable offset = 64
     BYVAL dwRequestID AS LONG _                        ' __in long dwRequestID
   )                                                    ' void
   ' =====================================================================================
   METHOD RequestComplete <1610743818> ( _              ' VTable offset = 68
     BYVAL dwRequestID AS LONG _                        ' __in long dwRequestID
   , BYVAL hrStatus AS LONG _                           ' __in long hrStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD BookMark <1610743819> ( _                     ' VTable offset = 72
     BYVAL dwBookMarkID AS LONG _                       ' __in long dwBookMarkID
   )                                                    ' void
   ' =====================================================================================
   METHOD Idle <1610743820> ( _                         ' VTable offset = 76
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bStart AS LONG _                             ' __in long bStart
   )                                                    ' void
   ' =====================================================================================
   METHOD Move <1610743821> ( _                         ' VTable offset = 80
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   , BYVAL dwCause AS LONG _                            ' __in long dwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD Size <1610743822> ( _                         ' VTable offset = 84
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL lWidth AS LONG _                             ' __in long lWidth
   , BYVAL lHeight AS LONG _                            ' __in long lHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD BalloonVisibleState <1610743823> ( _          ' VTable offset = 88
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bVisible AS LONG _                           ' __in long bVisible
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentNotifySinkEx Methods
   ' =====================================================================================
   METHOD HelpComplete <1610809344> ( _                 ' VTable offset = 92
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL dwCommandID AS LONG _                        ' __in long dwCommandID
   , BYVAL dwCause AS LONG _                            ' __in long dwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD ListeningState <1610809345> ( _               ' VTable offset = 96
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL bListening AS LONG _                         ' __in long bListening
   , BYVAL dwCause AS LONG _                            ' __in long dwCause
   )                                                    ' void
   ' =====================================================================================
   METHOD DefaultCharacterChange <1610809346> ( _       ' VTable offset = 100
     BYVAL bszGUID AS WSTRING _                          ' __in BSTR bszGUID
   )                                                    ' void
   ' =====================================================================================
   METHOD AgentPropertyChange <1610809347> ( _          ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD ActiveClientChange <1610809348> ( _           ' VTable offset = 108
     BYVAL dwCharID AS LONG _                           ' __in long dwCharID
   , BYVAL lStatus AS LONG _                            ' __in long lStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentNotifySinkEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentPrivateNotifySink
' IID = {B741B760-8EA6-11D0-AC6A-00C04FD97575}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAgentPrivateNotifySink_INTERFACE_DEFINED)
    %IAgentPrivateNotifySink_INTERFACE_DEFINED = 1

$IID_IAgentPrivateNotifySink = GUID$("{B741B760-8EA6-11D0-AC6A-00C04FD97575}")

INTERFACE IAgentPrivateNotifySink $IID_IAgentPrivateNotifySink

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ReleaseAll ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseOne ( _                                ' VTable offset = 16
     BYVAL pnNotify AS DWORD _                          ' __in void *pnNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClientID ( _                               ' VTable offset = 20
     BYREF pdwClientID AS DWORD _                       ' __out DWORD *pdwClientID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentPrivateNotifySink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCustomMarshalMaker
' IID = {408D7542-C8FC-11D1-AA83-00C04FA34D72}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAgentCustomMarshalMaker_INTERFACE_DEFINED)
    %IAgentCustomMarshalMaker_INTERFACE_DEFINED = 1

$IID_IAgentCustomMarshalMaker = GUID$("{408D7542-C8FC-11D1-AA83-00C04FA34D72}")

INTERFACE IAgentCustomMarshalMaker $IID_IAgentCustomMarshalMaker

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL pSink AS IUnknown _                          ' __in IUnknown *pSink
   , BYREF riidSink AS GUID _                           ' __in REFIID riidSink
   , BYREF pMarshaledSink AS IUnknown _                 ' __out IUnknown **pMarshaledSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCustomMarshalMaker_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentClientStatus
' IID = {C5649F70-7AED-11D1-B9A8-00C04FD97575}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAgentClientStatus_INTERFACE_DEFINED)
    %IAgentClientStatus_INTERFACE_DEFINED = 1

$IID_IAgentClientStatus = GUID$("{C5649F70-7AED-11D1-B9A8-00C04FD97575}")

INTERFACE IAgentClientStatus $IID_IAgentClientStatus

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Ping ( _                                      ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentClientStatus_INTERFACE_DEFINED__ */
