' ########################################################################################
' Microsoft Windows
' File: AgtCtl.inc
' Library name: AgentObjects
' Version: 2.0, Locale ID = 0
' Contents: Microsoft Agent Control 2.0
' Library GUID: {F5BE8BC2-7DE6-11D0-91FE-00C04FD701A5}
' Path: C:\WINDOWS\msagent\agentctl.dll
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AGTCTL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {D45FD31B-5C6E-11D1-9EC1-00C04FD7081F}
$PROGID_AgentControl2 = "Agent.Control.2"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {D45FD31B-5C6E-11D1-9EC1-00C04FD7081F}
$PROGID_AgentControl = "Agent.Control"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Agent                 = GUID$("{D45FD31B-5C6E-11D1-9EC1-00C04FD7081F}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAgentCtl               = GUID$("{F5BE8BD1-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlAnimationNames = GUID$("{8B77181C-D3EF-11D1-8500-00C04FA34A14}")
$IID_IAgentCtlAudioObject    = GUID$("{F5BE8BDB-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlAudioObjectEx  = GUID$("{F5BE8BF0-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlBalloon        = GUID$("{F5BE8BD3-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlBalloonEx      = GUID$("{822DB1C0-8879-11D1-9EC6-00C04FD7081F}")
$IID_IAgentCtlCharacter      = GUID$("{F5BE8BD9-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlCharacterEx    = GUID$("{DE8EF600-2F82-11D1-ACAC-00C04FD97575}")
$IID_IAgentCtlCharacters     = GUID$("{F5BE8BE8-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlCommand        = GUID$("{F5BE8BE3-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlCommandEx      = GUID$("{B0913410-3B44-11D1-ACBA-00C04FD97575}")
$IID_IAgentCtlCommands       = GUID$("{F5BE8BE1-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlCommandsEx     = GUID$("{6BA90C01-3910-11D1-ACB3-00C04FD97575}")
$IID_IAgentCtlCommandsWindow = GUID$("{6D0ECB27-9968-11D0-AC6E-00C04FD97575}")
$IID_IAgentCtlEx             = GUID$("{8563FF20-8ECC-11D1-B9B4-00C04FD97575}")
$IID_IAgentCtlPropertySheet  = GUID$("{F5BE8BDF-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlRequest        = GUID$("{1DAB85C3-803A-11D0-AC63-00C04FD97575}")
$IID_IAgentCtlSpeechInput    = GUID$("{F5BE8BDD-7DE6-11D0-91FE-00C04FD701A5}")
$IID_IAgentCtlUserInput      = GUID$("{C4ABF875-8100-11D0-AC63-00C04FD97575}")
$IID__AgentEvents            = GUID$("{F5BE8BD4-7DE6-11D0-91FE-00C04FD701A5}")

%RequestSuccess     = 0
%RequestFailed      = 1
%RequestPending     = 2
%RequestInterrupted = 3
%RequestInProgress  = 4


' ########################################################################################
' Interface name = IAgentCtlRequest
' IID = {1DAB85C3-803A-11D0-AC63-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlRequest_INTERFACE_DEFINED)
    %IAgentCtlRequest_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlRequest $IID_IAgentCtlRequest

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <0> ( _                              ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *ID
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY GET Description <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Description
   ' =====================================================================================
   PROPERTY GET Number <3> ( _                          ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *Number
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlRequest_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlUserInput
' IID = {C4ABF875-8100-11D0-AC63-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlUserInput_INTERFACE_DEFINED)
    %IAgentCtlUserInput_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlUserInput $IID_IAgentCtlUserInput

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *pCount
   ' =====================================================================================
   PROPERTY GET Name <1610743809> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY GET CharacterID <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pCharacterID
   ' =====================================================================================
   PROPERTY GET Confidence <1610743811> ( _             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pConfidence
   ' =====================================================================================
   PROPERTY GET Voice <1610743812> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVoice
   ' =====================================================================================
   PROPERTY GET Alt1Name <1610743813> ( _               ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pAlt1Name
   ' =====================================================================================
   PROPERTY GET Alt1Confidence <1610743814> ( _         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pAlt1Confidence
   ' =====================================================================================
   PROPERTY GET Alt1Voice <1610743815> ( _              ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pAlt1Voice
   ' =====================================================================================
   PROPERTY GET Alt2Name <1610743816> ( _               ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pAlt2Name
   ' =====================================================================================
   PROPERTY GET Alt2Confidence <1610743817> ( _         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pAlt2Confidence
   ' =====================================================================================
   PROPERTY GET Alt2Voice <1610743818> ( _              ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pAlt2Voice
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlUserInput_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlBalloon
' IID = {F5BE8BD3-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlBalloon_INTERFACE_DEFINED)
    %IAgentCtlBalloon_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlBalloon $IID_IAgentCtlBalloon

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Enabled <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Enabled
   ' =====================================================================================
   PROPERTY GET NumberOfLines <2> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Lines
   ' =====================================================================================
   PROPERTY GET CharsPerLine <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *CharsPerLine
   ' =====================================================================================
   PROPERTY GET FontName <4> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *FontName
   ' =====================================================================================
   PROPERTY GET FontSize <5> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *FontSize
   ' =====================================================================================
   PROPERTY GET FontBold <10> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontBold
   ' =====================================================================================
   PROPERTY GET FontItalic <11> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontItalic
   ' =====================================================================================
   PROPERTY GET FontStrikethru <12> ( _                 ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontStrikethru
   ' =====================================================================================
   PROPERTY GET FontUnderline <13> ( _                  ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontUnderline
   ' =====================================================================================
   PROPERTY GET ForeColor <7> ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *ForeColor
   ' =====================================================================================
   PROPERTY GET BackColor <8> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *BackColor
   ' =====================================================================================
   PROPERTY GET BorderColor <9> ( _                     ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *BorderColor
   ' =====================================================================================
   PROPERTY SET Visible <14> ( _                        ' VTable offset = 76
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <14> ( _                        ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET FontName <4> ( _                        ' VTable offset = 84
     BYVAL FontName AS WSTRING _                        ' __in BSTR FontName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET FontSize <5> ( _                        ' VTable offset = 88
     BYVAL FontSize AS LONG _                           ' __in long FontSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET FontCharSet <15> ( _                    ' VTable offset = 92
     BYVAL FontCharSet AS INTEGER _                     ' __in short FontCharSet
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontCharSet <15> ( _                    ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out short *FontCharSet
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlBalloon_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlBalloonEx
' IID = {822DB1C0-8879-11D1-9EC6-00C04FD7081F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCtlBalloon
' ########################################################################################

#IF NOT %DEF(%IAgentCtlBalloonEx_INTERFACE_DEFINED)
    %IAgentCtlBalloonEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlBalloonEx $IID_IAgentCtlBalloonEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCtlBalloon Methods
   ' =====================================================================================
   PROPERTY GET Enabled <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Enabled
   ' =====================================================================================
   PROPERTY GET NumberOfLines <2> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Lines
   ' =====================================================================================
   PROPERTY GET CharsPerLine <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *CharsPerLine
   ' =====================================================================================
   PROPERTY GET FontName <4> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *FontName
   ' =====================================================================================
   PROPERTY GET FontSize <5> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *FontSize
   ' =====================================================================================
   PROPERTY GET FontBold <10> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontBold
   ' =====================================================================================
   PROPERTY GET FontItalic <11> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontItalic
   ' =====================================================================================
   PROPERTY GET FontStrikethru <12> ( _                 ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontStrikethru
   ' =====================================================================================
   PROPERTY GET FontUnderline <13> ( _                  ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *FontUnderline
   ' =====================================================================================
   PROPERTY GET ForeColor <7> ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *ForeColor
   ' =====================================================================================
   PROPERTY GET BackColor <8> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *BackColor
   ' =====================================================================================
   PROPERTY GET BorderColor <9> ( _                     ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *BorderColor
   ' =====================================================================================
   PROPERTY SET Visible <14> ( _                        ' VTable offset = 76
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <14> ( _                        ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET FontName <4> ( _                        ' VTable offset = 84
     BYVAL FontName AS WSTRING _                        ' __in BSTR FontName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET FontSize <5> ( _                        ' VTable offset = 88
     BYVAL FontSize AS LONG _                           ' __in long FontSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET FontCharSet <15> ( _                    ' VTable offset = 92
     BYVAL FontCharSet AS INTEGER _                     ' __in short FontCharSet
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontCharSet <15> ( _                    ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out short *FontCharSet
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCtlBalloonEx Methods
   ' =====================================================================================
   PROPERTY SET Style <16> ( _                          ' VTable offset = 100
     BYVAL Style AS LONG _                              ' __in long Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <16> ( _                          ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *Style
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlBalloonEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCommand
' IID = {F5BE8BE3-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCommand_INTERFACE_DEFINED)
    %IAgentCtlCommand_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCommand $IID_IAgentCtlCommand

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Voice <1> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Voice
   ' =====================================================================================
   PROPERTY SET Voice <1> ( _                           ' VTable offset = 32
     BYVAL Voice AS WSTRING _                           ' __in BSTR Voice
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *Caption
   ' =====================================================================================
   PROPERTY SET Caption <2> ( _                         ' VTable offset = 40
     BYVAL Caption AS WSTRING _                         ' __in BSTR Caption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <5> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Enabled
   ' =====================================================================================
   PROPERTY SET Enabled <5> ( _                         ' VTable offset = 48
     BYVAL Enabled AS INTEGER _                         ' __in VARIANT_BOOL Enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <6> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Visible <6> ( _                         ' VTable offset = 56
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Confidence <3> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *Confidence
   ' =====================================================================================
   PROPERTY SET Confidence <3> ( _                      ' VTable offset = 64
     BYVAL Confidence AS LONG _                         ' __in long Confidence
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConfidenceText <4> ( _                  ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *Text
   ' =====================================================================================
   PROPERTY SET ConfidenceText <4> ( _                  ' VTable offset = 72
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCommandEx
' IID = {B0913410-3B44-11D1-ACBA-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCtlCommand
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCommandEx_INTERFACE_DEFINED)
    %IAgentCtlCommandEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCommandEx $IID_IAgentCtlCommandEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCtlCommand Methods
   ' =====================================================================================
   PROPERTY GET Voice <1> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Voice
   ' =====================================================================================
   PROPERTY SET Voice <1> ( _                           ' VTable offset = 32
     BYVAL Voice AS WSTRING _                           ' __in BSTR Voice
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Caption
   ' =====================================================================================
   PROPERTY SET Caption <2> ( _                         ' VTable offset = 40
     BYVAL Caption AS WSTRING _                         ' __in BSTR Caption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <5> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Enabled
   ' =====================================================================================
   PROPERTY SET Enabled <5> ( _                         ' VTable offset = 48
     BYVAL Enabled AS INTEGER _                         ' __in VARIANT_BOOL Enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <6> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Visible <6> ( _                         ' VTable offset = 56
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Confidence <3> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *Confidence
   ' =====================================================================================
   PROPERTY SET Confidence <3> ( _                      ' VTable offset = 64
     BYVAL Confidence AS LONG _                         ' __in long Confidence
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConfidenceText <4> ( _                  ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *Text
   ' =====================================================================================
   PROPERTY SET ConfidenceText <4> ( _                  ' VTable offset = 72
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCtlCommandEx Methods
   ' =====================================================================================
   PROPERTY SET HelpContextID <7> ( _                   ' VTable offset = 76
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpContextID <7> ( _                   ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *ID
   ' =====================================================================================
   PROPERTY SET VoiceCaption <8> ( _                    ' VTable offset = 84
     BYVAL VoiceCaption AS WSTRING _                    ' __in BSTR VoiceCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VoiceCaption <8> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *VoiceCaption
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCommandEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCommands
' IID = {F5BE8BE1-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCommands_INTERFACE_DEFINED)
    %IAgentCtlCommands_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCommands $IID_IAgentCtlCommands

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommandEx **Item
   ' =====================================================================================
   METHOD Command <15> ( _                              ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommandEx **Item
   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET Caption <3> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *Caption
   ' =====================================================================================
   PROPERTY SET Caption <3> ( _                         ' VTable offset = 44
     BYVAL Caption AS WSTRING _                         ' __in BSTR Caption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Voice <4> ( _                           ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Voice
   ' =====================================================================================
   PROPERTY SET Voice <4> ( _                           ' VTable offset = 52
     BYVAL Voice AS WSTRING _                           ' __in BSTR Voice
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <5> ( _                         ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Visible <5> ( _                         ' VTable offset = 60
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enum <-4> ( _                           ' VTable offset = 64
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkEnum
   ' =====================================================================================
   METHOD Add <10> ( _                                  ' VTable offset = 68
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Caption AS VARIANT _                ' __opt_in VARIANT Caption
   , OPTIONAL BYVAL Voice AS VARIANT _                  ' __opt_in VARIANT Voice
   , OPTIONAL BYVAL Enabled AS VARIANT _                ' __opt_in VARIANT Enabled
   , OPTIONAL BYVAL Visible AS VARIANT _                ' __opt_in VARIANT Visible
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommand **Command
   ' =====================================================================================
   METHOD Insert <11> ( _                               ' VTable offset = 72
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL RefName AS WSTRING _                         ' __in BSTR RefName
   , OPTIONAL BYVAL Before AS VARIANT _                 ' __opt_in VARIANT Before
   , OPTIONAL BYVAL Caption AS VARIANT _                ' __opt_in VARIANT Caption
   , OPTIONAL BYVAL Voice AS VARIANT _                  ' __opt_in VARIANT Voice
   , OPTIONAL BYVAL Enabled AS VARIANT _                ' __opt_in VARIANT Enabled
   , OPTIONAL BYVAL Visible AS VARIANT _                ' __opt_in VARIANT Visible
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommand **Command
   ' =====================================================================================
   METHOD Remove <13> ( _                               ' VTable offset = 76
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <14> ( _                            ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCommands_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCommandsEx
' IID = {6BA90C01-3910-11D1-ACB3-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCtlCommands
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCommandsEx_INTERFACE_DEFINED)
    %IAgentCtlCommandsEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCommandsEx $IID_IAgentCtlCommandsEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCtlCommands Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommandEx **Item
   ' =====================================================================================
   METHOD Command <15> ( _                              ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommandEx **Item
   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET Caption <3> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *Caption
   ' =====================================================================================
   PROPERTY SET Caption <3> ( _                         ' VTable offset = 44
     BYVAL Caption AS WSTRING _                         ' __in BSTR Caption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Voice <4> ( _                           ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Voice
   ' =====================================================================================
   PROPERTY SET Voice <4> ( _                           ' VTable offset = 52
     BYVAL Voice AS WSTRING _                           ' __in BSTR Voice
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <5> ( _                         ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Visible <5> ( _                         ' VTable offset = 60
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enum <-4> ( _                           ' VTable offset = 64
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkEnum
   ' =====================================================================================
   METHOD Add <10> ( _                                  ' VTable offset = 68
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Caption AS VARIANT _                ' __opt_in VARIANT Caption
   , OPTIONAL BYVAL Voice AS VARIANT _                  ' __opt_in VARIANT Voice
   , OPTIONAL BYVAL Enabled AS VARIANT _                ' __opt_in VARIANT Enabled
   , OPTIONAL BYVAL Visible AS VARIANT _                ' __opt_in VARIANT Visible
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommand **Command
   ' =====================================================================================
   METHOD Insert <11> ( _                               ' VTable offset = 72
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL RefName AS WSTRING _                         ' __in BSTR RefName
   , OPTIONAL BYVAL Before AS VARIANT _                 ' __opt_in VARIANT Before
   , OPTIONAL BYVAL Caption AS VARIANT _                ' __opt_in VARIANT Caption
   , OPTIONAL BYVAL Voice AS VARIANT _                  ' __opt_in VARIANT Voice
   , OPTIONAL BYVAL Enabled AS VARIANT _                ' __opt_in VARIANT Enabled
   , OPTIONAL BYVAL Visible AS VARIANT _                ' __opt_in VARIANT Visible
   ) AS IAgentCtlCommand                                ' __retval_out IAgentCtlCommand **Command
   ' =====================================================================================
   METHOD Remove <13> ( _                               ' VTable offset = 76
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <14> ( _                            ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCtlCommandsEx Methods
   ' =====================================================================================
   PROPERTY SET DefaultCommand <16> ( _                 ' VTable offset = 84
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultCommand <16> ( _                 ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET HelpContextID <17> ( _                  ' VTable offset = 92
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpContextID <17> ( _                  ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *ID
   ' =====================================================================================
   PROPERTY SET FontName <21> ( _                       ' VTable offset = 100
     BYVAL FontName AS WSTRING _                        ' __in BSTR FontName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FontName <21> ( _                       ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *FontName
   ' =====================================================================================
   PROPERTY GET FontSize <23> ( _                       ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *FontSize
   ' =====================================================================================
   PROPERTY SET FontSize <23> ( _                       ' VTable offset = 112
     BYVAL FontSize AS LONG _                           ' __in long FontSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET VoiceCaption <22> ( _                   ' VTable offset = 116
     BYVAL VoiceCaption AS WSTRING _                    ' __in BSTR VoiceCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VoiceCaption <22> ( _                   ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *VoiceCaption
   ' =====================================================================================
   PROPERTY SET GlobalVoiceCommandsEnabled <23> ( _     ' VTable offset = 124
     BYVAL Enable AS INTEGER _                          ' __in VARIANT_BOOL Enable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GlobalVoiceCommandsEnabled <24> ( _     ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Enable
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCommandsEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCharacter
' IID = {F5BE8BD9-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCharacter_INTERFACE_DEFINED)
    %IAgentCtlCharacter_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCharacter $IID_IAgentCtlCharacter

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Balloon <23> ( _                        ' VTable offset = 28
   ) AS IAgentCtlBalloon                                ' __retval_out IAgentCtlBalloonEx **ppidBalloon
   ' =====================================================================================
   PROPERTY GET Commands <25> ( _                       ' VTable offset = 32
   ) AS IAgentCtlCommands                               ' __retval_out IAgentCtlCommandsEx **ppidCommands
   ' =====================================================================================
   PROPERTY GET Name <24> ( _                           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Description <28> ( _                    ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *Description
   ' =====================================================================================
   PROPERTY GET Visible <2> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Left <3> ( _                            ' VTable offset = 48
     BYVAL Left AS INTEGER _                            ' __in short Left
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <3> ( _                            ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short *Left
   ' =====================================================================================
   PROPERTY SET Top <4> ( _                             ' VTable offset = 56
     BYVAL Top AS INTEGER _                             ' __in short Top
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <4> ( _                             ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short *Top
   ' =====================================================================================
   PROPERTY SET Height <5> ( _                          ' VTable offset = 64
     BYVAL Height AS INTEGER _                          ' __in short Height
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <5> ( _                          ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short *Height
   ' =====================================================================================
   PROPERTY SET Width <6> ( _                           ' VTable offset = 72
     BYVAL Width AS INTEGER _                           ' __in short Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <6> ( _                           ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short *Width
   ' =====================================================================================
   PROPERTY GET Speed <10> ( _                          ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *Speed
   ' =====================================================================================
   PROPERTY GET Pitch <11> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *Pitch
   ' =====================================================================================
   PROPERTY SET IdleOn <29> ( _                         ' VTable offset = 88
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IdleOn <29> ( _                         ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   METHOD Activate <26> ( _                             ' VTable offset = 96
     OPTIONAL BYVAL State AS VARIANT _                  ' __opt_in VARIANT State
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Success
   ' =====================================================================================
   METHOD Play <13> ( _                                 ' VTable offset = 100
     BYVAL Animation AS WSTRING _                       ' __in BSTR Animation
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Get <27> ( _                                  ' VTable offset = 104
     BYVAL Type AS WSTRING _                            ' __in BSTR Type
   , BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Queue AS VARIANT _                  ' __opt_in VARIANT Queue
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Stop <14> ( _                                 ' VTable offset = 108
     OPTIONAL BYVAL Request AS VARIANT _                ' __opt_in VARIANT Request
   )                                                    ' void
   ' =====================================================================================
   METHOD Wait <22> ( _                                 ' VTable offset = 112
     BYVAL WaitForRequest AS IDispatch _                ' __in IDispatch *WaitForRequest
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Interrupt <21> ( _                            ' VTable offset = 116
     BYVAL InterruptRequest AS IDispatch _              ' __in IDispatch *InterruptRequest
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Speak <15> ( _                                ' VTable offset = 120
     OPTIONAL BYVAL Text AS VARIANT _                   ' __opt_in VARIANT Text
   , OPTIONAL BYVAL Url AS VARIANT _                    ' __opt_in VARIANT Url
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD GestureAt <17> ( _                            ' VTable offset = 124
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD MoveTo <18> ( _                               ' VTable offset = 128
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   , OPTIONAL BYVAL Speed AS VARIANT _                  ' __opt_in VARIANT Speed
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Hide <19> ( _                                 ' VTable offset = 132
     OPTIONAL BYVAL Fast AS VARIANT _                   ' __opt_in VARIANT Fast
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Show <20> ( _                                 ' VTable offset = 136
     OPTIONAL BYVAL Fast AS VARIANT _                   ' __opt_in VARIANT Fast
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD StopAll <31> ( _                              ' VTable offset = 140
     OPTIONAL BYVAL Types AS VARIANT _                  ' __opt_in VARIANT Types
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MoveCause <32> ( _                      ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out short *MoveCause
   ' =====================================================================================
   PROPERTY GET VisibilityCause <33> ( _                ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out short *VisibilityCause
   ' =====================================================================================
   PROPERTY GET HasOtherClients <34> ( _                ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *HasOtherClients
   ' =====================================================================================
   PROPERTY SET SoundEffectsOn <35> ( _                 ' VTable offset = 156
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SoundEffectsOn <35> ( _                 ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   PROPERTY SET Name <24> ( _                           ' VTable offset = 164
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Description <28> ( _                    ' VTable offset = 168
     BYVAL Description AS WSTRING _                     ' __in BSTR Description
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExtraData <36> ( _                      ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR *ExtraData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCharacter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlAnimationNames
' IID = {8B77181C-D3EF-11D1-8500-00C04FA34A14}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlAnimationNames_INTERFACE_DEFINED)
    %IAgentCtlAnimationNames_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlAnimationNames $IID_IAgentCtlAnimationNames

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Enum <-4> ( _                           ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlAnimationNames_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCharacterEx
' IID = {DE8EF600-2F82-11D1-ACAC-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCtlCharacter
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCharacterEx_INTERFACE_DEFINED)
    %IAgentCtlCharacterEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCharacterEx $IID_IAgentCtlCharacterEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCtlCharacter Methods
   ' =====================================================================================
   PROPERTY GET Balloon <23> ( _                        ' VTable offset = 28
   ) AS IAgentCtlBalloon                                ' __retval_out IAgentCtlBalloonEx **ppidBalloon
   ' =====================================================================================
   PROPERTY GET Commands <25> ( _                       ' VTable offset = 32
   ) AS IAgentCtlCommands                               ' __retval_out IAgentCtlCommandsEx **ppidCommands
   ' =====================================================================================
   PROPERTY GET Name <24> ( _                           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Description <28> ( _                    ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *Description
   ' =====================================================================================
   PROPERTY GET Visible <2> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Left <3> ( _                            ' VTable offset = 48
     BYVAL Left AS INTEGER _                            ' __in short Left
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <3> ( _                            ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short *Left
   ' =====================================================================================
   PROPERTY SET Top <4> ( _                             ' VTable offset = 56
     BYVAL Top AS INTEGER _                             ' __in short Top
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <4> ( _                             ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short *Top
   ' =====================================================================================
   PROPERTY SET Height <5> ( _                          ' VTable offset = 64
     BYVAL Height AS INTEGER _                          ' __in short Height
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <5> ( _                          ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short *Height
   ' =====================================================================================
   PROPERTY SET Width <6> ( _                           ' VTable offset = 72
     BYVAL Width AS INTEGER _                           ' __in short Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <6> ( _                           ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short *Width
   ' =====================================================================================
   PROPERTY GET Speed <10> ( _                          ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *Speed
   ' =====================================================================================
   PROPERTY GET Pitch <11> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *Pitch
   ' =====================================================================================
   PROPERTY SET IdleOn <29> ( _                         ' VTable offset = 88
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IdleOn <29> ( _                         ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   METHOD Activate <26> ( _                             ' VTable offset = 96
     OPTIONAL BYVAL State AS VARIANT _                  ' __opt_in VARIANT State
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Success
   ' =====================================================================================
   METHOD Play <13> ( _                                 ' VTable offset = 100
     BYVAL Animation AS WSTRING _                       ' __in BSTR Animation
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Get <27> ( _                                  ' VTable offset = 104
     BYVAL Type AS WSTRING _                            ' __in BSTR Type
   , BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Queue AS VARIANT _                  ' __opt_in VARIANT Queue
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Stop <14> ( _                                 ' VTable offset = 108
     OPTIONAL BYVAL Request AS VARIANT _                ' __opt_in VARIANT Request
   )                                                    ' void
   ' =====================================================================================
   METHOD Wait <22> ( _                                 ' VTable offset = 112
     BYVAL WaitForRequest AS IDispatch _                ' __in IDispatch *WaitForRequest
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Interrupt <21> ( _                            ' VTable offset = 116
     BYVAL InterruptRequest AS IDispatch _              ' __in IDispatch *InterruptRequest
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Speak <15> ( _                                ' VTable offset = 120
     OPTIONAL BYVAL Text AS VARIANT _                   ' __opt_in VARIANT Text
   , OPTIONAL BYVAL Url AS VARIANT _                    ' __opt_in VARIANT Url
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD GestureAt <17> ( _                            ' VTable offset = 124
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD MoveTo <18> ( _                               ' VTable offset = 128
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   , OPTIONAL BYVAL Speed AS VARIANT _                  ' __opt_in VARIANT Speed
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Hide <19> ( _                                 ' VTable offset = 132
     OPTIONAL BYVAL Fast AS VARIANT _                   ' __opt_in VARIANT Fast
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD Show <20> ( _                                 ' VTable offset = 136
     OPTIONAL BYVAL Fast AS VARIANT _                   ' __opt_in VARIANT Fast
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   METHOD StopAll <31> ( _                              ' VTable offset = 140
     OPTIONAL BYVAL Types AS VARIANT _                  ' __opt_in VARIANT Types
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MoveCause <32> ( _                      ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out short *MoveCause
   ' =====================================================================================
   PROPERTY GET VisibilityCause <33> ( _                ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out short *VisibilityCause
   ' =====================================================================================
   PROPERTY GET HasOtherClients <34> ( _                ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *HasOtherClients
   ' =====================================================================================
   PROPERTY SET SoundEffectsOn <35> ( _                 ' VTable offset = 156
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SoundEffectsOn <35> ( _                 ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   PROPERTY SET Name <24> ( _                           ' VTable offset = 164
     BYVAL Name AS WSTRING _                             ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Description <28> ( _                    ' VTable offset = 168
     BYVAL Description AS WSTRING _                     ' __in BSTR Description
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExtraData <36> ( _                      ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR *ExtraData
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCtlCharacterEx Methods
   ' =====================================================================================
   METHOD ShowPopupMenu <37> ( _                        ' VTable offset = 176
     BYVAL x AS INTEGER _                               ' __in short x
   , BYVAL y AS INTEGER _                               ' __in short y
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Showed
   ' =====================================================================================
   PROPERTY SET AutoPopupMenu <38> ( _                  ' VTable offset = 180
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoPopupMenu <38> ( _                  ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   PROPERTY SET HelpModeOn <39> ( _                     ' VTable offset = 188
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpModeOn <39> ( _                     ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   PROPERTY SET HelpContextID <40> ( _                  ' VTable offset = 196
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpContextID <40> ( _                  ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *ID
   ' =====================================================================================
   PROPERTY GET Active <41> ( _                         ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out short *State
   ' =====================================================================================
   METHOD Listen <42> ( _                               ' VTable offset = 208
     BYVAL Listen AS INTEGER _                          ' __in VARIANT_BOOL Listen
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *StartedListening
   ' =====================================================================================
   PROPERTY SET LanguageID <43> ( _                     ' VTable offset = 212
     BYVAL LanguageID AS LONG _                         ' __in long LanguageID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LanguageID <43> ( _                     ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *LanguageID
   ' =====================================================================================
   PROPERTY GET SRModeID <46> ( _                       ' VTable offset = 220
   ) AS WSTRING                                         ' __retval_out BSTR *EngineModeId
   ' =====================================================================================
   PROPERTY SET SRModeID <46> ( _                       ' VTable offset = 224
     BYVAL EngineModeId AS WSTRING _                    ' __in BSTR EngineModeId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TTSModeID <47> ( _                      ' VTable offset = 228
   ) AS WSTRING                                          ' __retval_out BSTR *EngineModeId
   ' =====================================================================================
   PROPERTY SET TTSModeID <47> ( _                      ' VTable offset = 232
     BYVAL EngineModeId AS WSTRING _                    ' __in BSTR EngineModeId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpFile <48> ( _                       ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *File
   ' =====================================================================================
   PROPERTY SET HelpFile <48> ( _                       ' VTable offset = 240
     BYVAL File AS WSTRING _                            ' __in BSTR File
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GUID <49> ( _                           ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *GUID
   ' =====================================================================================
   PROPERTY GET OriginalHeight <50> ( _                 ' VTable offset = 248
   ) AS INTEGER                                         ' __retval_out short *Height
   ' =====================================================================================
   PROPERTY GET OriginalWidth <51> ( _                  ' VTable offset = 252
   ) AS INTEGER                                         ' __retval_out short *Width
   ' =====================================================================================
   METHOD Think <52> ( _                                ' VTable offset = 256
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **Request
   ' =====================================================================================
   PROPERTY GET Version <53> ( _                        ' VTable offset = 260
   ) AS WSTRING                                         ' __retval_out BSTR *Version
   ' =====================================================================================
   PROPERTY GET AnimationNames <54> ( _                 ' VTable offset = 264
   ) AS IAgentCtlAnimationNames                         ' __retval_out IAgentCtlAnimationNames **Names
   ' =====================================================================================
   PROPERTY GET SRStatus <55> ( _                       ' VTable offset = 268
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCharacterEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCharacters
' IID = {F5BE8BE8-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCharacters_INTERFACE_DEFINED)
    %IAgentCtlCharacters_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCharacters $IID_IAgentCtlCharacters

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL CharacterID AS WSTRING _                     ' __in BSTR CharacterID
   ) AS IAgentCtlCharacter                              ' __retval_out IAgentCtlCharacterEx **ppidItem
   ' =====================================================================================
   METHOD Character <3> ( _                             ' VTable offset = 32
     BYVAL CharacterID AS WSTRING _                     ' __in BSTR CharacterID
   ) AS IAgentCtlCharacterEx                            ' __retval_out IAgentCtlCharacterEx **ppidItem
   ' =====================================================================================
   PROPERTY GET Enum <-4> ( _                           ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkEnum
   ' =====================================================================================
   METHOD Unload <2> ( _                                ' VTable offset = 40
     BYVAL CharacterID AS WSTRING _                     ' __in BSTR CharacterID
   )                                                    ' void
   ' =====================================================================================
   METHOD Load <1> ( _                                  ' VTable offset = 44
     BYVAL CharacterID AS WSTRING _                     ' __in BSTR CharacterID
   , OPTIONAL BYVAL LoadKey AS VARIANT _                ' __opt_in VARIANT LoadKey
   ) AS IAgentCtlRequest                                ' __retval_out IAgentCtlRequest **ppidRequest
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCharacters_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlAudioObject
' IID = {F5BE8BDB-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlAudioObject_INTERFACE_DEFINED)
    %IAgentCtlAudioObject_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlAudioObject $IID_IAgentCtlAudioObject

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Enabled <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *AudioEnabled
   ' =====================================================================================
   PROPERTY GET SoundEffects <2> ( _                    ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *SoundEffects
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlAudioObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlAudioObjectEx
' IID = {F5BE8BF0-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCtlAudioObject
' ########################################################################################

#IF NOT %DEF(%IAgentCtlAudioObjectEx_INTERFACE_DEFINED)
    %IAgentCtlAudioObjectEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlAudioObjectEx $IID_IAgentCtlAudioObjectEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCtlAudioObject Methods
   ' =====================================================================================
   PROPERTY GET Enabled <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *AudioEnabled
   ' =====================================================================================
   PROPERTY GET SoundEffects <2> ( _                    ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *SoundEffects
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCtlAudioObjectEx Methods
   ' =====================================================================================
   PROPERTY GET Status <3> ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short *Available
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlAudioObjectEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlSpeechInput
' IID = {F5BE8BDD-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlSpeechInput_INTERFACE_DEFINED)
    %IAgentCtlSpeechInput_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlSpeechInput $IID_IAgentCtlSpeechInput

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Enabled <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *VoiceEnabled
   ' =====================================================================================
   PROPERTY GET Language <2> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *Language
   ' =====================================================================================
   PROPERTY GET HotKey <3> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *HotKey
   ' =====================================================================================
   PROPERTY GET Installed <4> ( _                       ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *VoiceInstalled
   ' =====================================================================================
   PROPERTY GET Engine <5> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Engine
   ' =====================================================================================
   PROPERTY SET Engine <5> ( _                          ' VTable offset = 48
     BYVAL Engine AS WSTRING _                          ' __in BSTR Engine
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListeningTip <6> ( _                    ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *ListeningTip
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlSpeechInput_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlPropertySheet
' IID = {F5BE8BDF-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlPropertySheet_INTERFACE_DEFINED)
    %IAgentCtlPropertySheet_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlPropertySheet $IID_IAgentCtlPropertySheet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Left <1> ( _                            ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short *Left
   ' =====================================================================================
   PROPERTY GET Top <2> ( _                             ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out short *Top
   ' =====================================================================================
   PROPERTY GET Height <3> ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short *Height
   ' =====================================================================================
   PROPERTY GET Width <4> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *Width
   ' =====================================================================================
   PROPERTY SET Visible <6> ( _                         ' VTable offset = 44
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <6> ( _                         ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Page <5> ( _                            ' VTable offset = 52
     BYVAL Page AS WSTRING _                            ' __in BSTR Page
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Page <5> ( _                            ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *Page
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlPropertySheet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlCommandsWindow
' IID = {6D0ECB27-9968-11D0-AC6E-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtlCommandsWindow_INTERFACE_DEFINED)
    %IAgentCtlCommandsWindow_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlCommandsWindow $IID_IAgentCtlCommandsWindow

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Visible <5> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Visible <5> ( _                         ' VTable offset = 32
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <6> ( _                            ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short *Left
   ' =====================================================================================
   PROPERTY GET Top <7> ( _                             ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *Top
   ' =====================================================================================
   PROPERTY GET Height <8> ( _                          ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *Height
   ' =====================================================================================
   PROPERTY GET Width <9> ( _                           ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out short *Width
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlCommandsWindow_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtl
' IID = {F5BE8BD1-7DE6-11D0-91FE-00C04FD701A5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAgentCtl_INTERFACE_DEFINED)
    %IAgentCtl_INTERFACE_DEFINED = 1

INTERFACE IAgentCtl $IID_IAgentCtl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Characters <3> ( _                      ' VTable offset = 28
   ) AS IAgentCtlCharacters                             ' __retval_out IAgentCtlCharacters **Characters
   ' =====================================================================================
   PROPERTY GET AudioOutput <4> ( _                     ' VTable offset = 32
   ) AS IAgentCtlAudioObject                            ' __retval_out IAgentCtlAudioObjectEx **AudioOutput
   ' =====================================================================================
   PROPERTY GET SpeechInput <5> ( _                     ' VTable offset = 36
   ) AS IAgentCtlSpeechInput                            ' __retval_out IAgentCtlSpeechInput **SpeechInput
   ' =====================================================================================
   PROPERTY GET PropertySheet <8> ( _                   ' VTable offset = 40
   ) AS IAgentCtlPropertySheet                          ' __retval_out IAgentCtlPropertySheet **PropSheet
   ' =====================================================================================
   PROPERTY GET CommandsWindow <12> ( _                 ' VTable offset = 44
   ) AS IAgentCtlCommandsWindow                         ' __retval_out IAgentCtlCommandsWindow **CommandsWindow
   ' =====================================================================================
   PROPERTY GET Connected <9> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Connected
   ' =====================================================================================
   PROPERTY SET Connected <9> ( _                       ' VTable offset = 52
     BYVAL Connected AS INTEGER _                       ' __in VARIANT_BOOL Connected
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Suspended <14> ( _                      ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Suspended
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAgentCtlEx
' IID = {8563FF20-8ECC-11D1-B9B4-00C04FD97575}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAgentCtl
' ########################################################################################

#IF NOT %DEF(%IAgentCtlEx_INTERFACE_DEFINED)
    %IAgentCtlEx_INTERFACE_DEFINED = 1

INTERFACE IAgentCtlEx $IID_IAgentCtlEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAgentCtl Methods
   ' =====================================================================================
   PROPERTY GET Characters <3> ( _                      ' VTable offset = 28
   ) AS IAgentCtlCharacters                             ' __retval_out IAgentCtlCharacters **Characters
   ' =====================================================================================
   PROPERTY GET AudioOutput <4> ( _                     ' VTable offset = 32
   ) AS IAgentCtlAudioObject                            ' __retval_out IAgentCtlAudioObjectEx **AudioOutput
   ' =====================================================================================
   PROPERTY GET SpeechInput <5> ( _                     ' VTable offset = 36
   ) AS IAgentCtlSpeechInput                            ' __retval_out IAgentCtlSpeechInput **SpeechInput
   ' =====================================================================================
   PROPERTY GET PropertySheet <8> ( _                   ' VTable offset = 40
   ) AS IAgentCtlPropertySheet                          ' __retval_out IAgentCtlPropertySheet **PropSheet
   ' =====================================================================================
   PROPERTY GET CommandsWindow <12> ( _                 ' VTable offset = 44
   ) AS IAgentCtlCommandsWindow                         ' __retval_out IAgentCtlCommandsWindow **CommandsWindow
   ' =====================================================================================
   PROPERTY GET Connected <9> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Connected
   ' =====================================================================================
   PROPERTY SET Connected <9> ( _                       ' VTable offset = 52
     BYVAL Connected AS INTEGER _                       ' __in VARIANT_BOOL Connected
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Suspended <14> ( _                      ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Suspended
   ' =====================================================================================

   ' =====================================================================================
   ' IAgentCtlEx Methods
   ' =====================================================================================
   METHOD ShowDefaultCharacterProperties <20> ( _       ' VTable offset = 60
     OPTIONAL BYVAL x AS VARIANT _                      ' __opt_in VARIANT x
   , OPTIONAL BYVAL y AS VARIANT _                      ' __opt_in VARIANT y
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RaiseRequestErrors <21> ( _             ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RaiseErrors
   ' =====================================================================================
   PROPERTY SET RaiseRequestErrors <21> ( _             ' VTable offset = 68
     BYVAL RaiseErrors AS INTEGER _                     ' __in VARIANT_BOOL RaiseErrors
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAgentCtlEx_INTERFACE_DEFINED__ */
