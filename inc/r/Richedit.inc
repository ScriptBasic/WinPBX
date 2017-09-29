' ########################################################################################
' Microsoft Windows
' File: Richedit.inc
' Contents: RICHEDIT v2.0/3.0/4.0 public definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RICHEDIT_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "commctrl.inc"

'#ifdef _WIN32
'#include <pshpack4.h>
'#endif

'// To mimic older RichEdit behavior, set _RICHEDIT_VER to appropriate value
'//      Version 1.0      0x0100
'//      Version 2.0      0x0200
'//      Version 2.1      0x0210
#IF NOT %DEF(%RICHEDIT_VER)
  %RICHEDIT_VER = &H0300
#ENDIF

%cchTextLimitDefault = 32767

$$MSFTEDIT_CLASS = "RICHEDIT50W"$$

'// NOTE:  MSFTEDIT.DLL only registers MSFTEDIT_CLASS.  If an application wants
'// to use the following Richedit classes, it needs to load the riched20.dll.
'// Otherwise, CreateWindow with RICHEDIT_CLASS would fail.
'// This also applies to any dialog that uses RICHEDIT_CLASS,

'// RichEdit 2.0 Window Class
'// On Windows CE, avoid possible conflicts on Win95
'#define CERICHEDIT_CLASSA   "RichEditCEA"
'#define CERICHEDIT_CLASSW   L"RichEditCEW"
$CERICHEDIT_CLASSA  = "RichEditCEA"
$$CERICHEDIT_CLASSW = "RichEditCEW"$$

'#define RICHEDIT_CLASSA      "RichEdit20A"
'#define RICHEDIT_CLASS10A    "RICHEDIT"         // Richedit 1.0
$RICHEDIT_CLASSA = "RichEdit20A"
$RICHEDIT_CLASS10A = "RICHEDIT"   ' //Richedit 1.0
$$RICHEDIT_CLASSW = "RichEdit20W"$$

#IF (%RICHEDIT_VER - &H0100)
   ' %RICHEDIT_VER presumed > &H0100
   $RICHEDIT_CLASS = "RichEdit20A"
#ELSE
   $RICHEDIT_CLASS = "RICHEDIT"
#ENDIF

#IF (%RICHEDIT_VER >= &H0200)
   #IF %DEF(%UNICODE)
      MACRO RICHEDIT_CLASS = $$RICHEDIT_CLASSW
   #ELSE
      MACRO RICHEDIT_CLASS = $RICHEDIT_CLASSA
   #ENDIF ' %UNICODE
#ELSE
   $RICHEDIT_CLASS = $RICHEDIT_CLASS10A
   MACRO RICHEDIT_CLASS = $RICHEDIT_CLASS10A
#ENDIF ' %RICHEDIT_VER >= &H0200

'// RichEdit messages

#IF NOT %DEF(%WM_CONTEXTMENU)
   %WM_CONTEXTMENU     = &H007B
#ENDIF

#IF NOT %DEF(%WM_UNICHAR)
   %WM_UNICHAR         = &H0109
#ENDIF

#IF NOT %DEF(%WM_PRINTCLIENT)
   %WM_PRINTCLIENT     = &H0318
#ENDIF

#IF NOT %DEF(%EM_GETLIMITTEXT)
   %EM_GETLIMITTEXT    = %WM_USER + 37
#ENDIF

#IF NOT %DEF(%EM_POSFROMCHAR)
   %EM_POSFROMCHAR     = %WM_USER + 38
   %EM_CHARFROMPOS     = %WM_USER + 39
#ENDIF

#IF NOT %DEF(%EM_SCROLLCARET)
   %EM_SCROLLCARET     = %WM_USER + 49
#ENDIF
%EM_CANPASTE           = %WM_USER + 50
%EM_DISPLAYBAND        = %WM_USER + 51
%EM_EXGETSEL           = %WM_USER + 52
%EM_EXLIMITTEXT        = %WM_USER + 53
%EM_EXLINEFROMCHAR     = %WM_USER + 54
%EM_EXSETSEL           = %WM_USER + 55
%EM_FINDTEXT           = %WM_USER + 56
%EM_FORMATRANGE        = %WM_USER + 57
%EM_GETCHARFORMAT      = %WM_USER + 58
%EM_GETEVENTMASK       = %WM_USER + 59
%EM_GETOLEINTERFACE    = %WM_USER + 60
%EM_GETPARAFORMAT      = %WM_USER + 61
%EM_GETSELTEXT         = %WM_USER + 62
%EM_HIDESELECTION      = %WM_USER + 63
%EM_PASTESPECIAL       = %WM_USER + 64
%EM_REQUESTRESIZE      = %WM_USER + 65
%EM_SELECTIONTYPE      = %WM_USER + 66
%EM_SETBKGNDCOLOR      = %WM_USER + 67
%EM_SETCHARFORMAT      = %WM_USER + 68
%EM_SETEVENTMASK       = %WM_USER + 69
%EM_SETOLECALLBACK     = %WM_USER + 70
%EM_SETPARAFORMAT      = %WM_USER + 71
%EM_SETTARGETDEVICE    = %WM_USER + 72
%EM_STREAMIN           = %WM_USER + 73
%EM_STREAMOUT          = %WM_USER + 74
%EM_GETTEXTRANGE       = %WM_USER + 75
%EM_FINDWORDBREAK      = %WM_USER + 76
%EM_SETOPTIONS         = %WM_USER + 77
%EM_GETOPTIONS         = %WM_USER + 78
%EM_FINDTEXTEX         = %WM_USER + 79
'#ifdef _WIN32
%EM_GETWORDBREAKPROCEX = %WM_USER + 80
%EM_SETWORDBREAKPROCEX = %WM_USER + 81
'#endif

'// RichEdit 2.0 messages
%EM_SETUNDOLIMIT       = %WM_USER + 82
%EM_REDO               = %WM_USER + 84
%EM_CANREDO            = %WM_USER + 85
%EM_GETUNDONAME        = %WM_USER + 86
%EM_GETREDONAME        = %WM_USER + 87
%EM_STOPGROUPTYPING    = %WM_USER + 88

%EM_SETTEXTMODE        = %WM_USER + 89
%EM_GETTEXTMODE        = %WM_USER + 90

'// enum for use with EM_GET/SETTEXTMODE
' TEXTMODE enum
%TM_PLAINTEXT       = 1
%TM_RICHTEXT        = 2     ' default behavior
%TM_SINGLELEVELUNDO = 4
%TM_MULTILEVELUNDO  = 8     ' default behavior
%TM_SINGLECODEPAGE  = 16
%TM_MULTICODEPAGE   = 32    ' default behavior

%EM_AUTOURLDETECT      = %WM_USER + 91
%EM_GETAUTOURLDETECT   = %WM_USER + 92
%EM_SETPALETTE         = %WM_USER + 93
%EM_GETTEXTEX          = %WM_USER + 94
%EM_GETTEXTLENGTHEX    = %WM_USER + 95
%EM_SHOWSCROLLBAR      = %WM_USER + 96
%EM_SETTEXTEX          = %WM_USER + 97

'// East Asia specific messages
%EM_SETPUNCTUATION  = %WM_USER + 100
%EM_GETPUNCTUATION  = %WM_USER + 101
%EM_SETWORDWRAPMODE = %WM_USER + 102
%EM_GETWORDWRAPMODE = %WM_USER + 103
%EM_SETIMECOLOR     = %WM_USER + 104
%EM_GETIMECOLOR     = %WM_USER + 105
%EM_SETIMEOPTIONS   = %WM_USER + 106
%EM_GETIMEOPTIONS   = %WM_USER + 107
%EM_CONVPOSITION    = %WM_USER + 108

%EM_SETLANGOPTIONS  = %WM_USER + 120
%EM_GETLANGOPTIONS  = %WM_USER + 121
%EM_GETIMECOMPMODE  = %WM_USER + 122

%EM_FINDTEXTW       = %WM_USER + 123
%EM_FINDTEXTEXW     = %WM_USER + 124

'// RE3.0 FE messages
%EM_RECONVERSION    = %WM_USER + 125
%EM_SETIMEMODEBIAS  = %WM_USER + 126
%EM_GETIMEMODEBIAS  = %WM_USER + 127

'// BiDi specific messages
%EM_SETBIDIOPTIONS  = %WM_USER + 200
%EM_GETBIDIOPTIONS  = %WM_USER + 201

%EM_SETTYPOGRAPHYOPTIONS = %WM_USER + 202
%EM_GETTYPOGRAPHYOPTIONS = %WM_USER + 203

'// Extended edit style specific messages
%EM_SETEDITSTYLE    = %WM_USER + 204
%EM_GETEDITSTYLE    = %WM_USER + 205

'// Extended edit style masks
%SES_EMULATESYSEDIT      = 1
%SES_BEEPONMAXTEXT       = 2
%SES_EXTENDBACKCOLOR     = 4
%SES_MAPCPS              = 8
%SES_EMULATE10           = 16
%SES_USECRLF             = 32
%SES_USEAIMM             = 64
%SES_NOIME               = 128

%SES_ALLOWBEEPS          = 256
%SES_UPPERCASE           = 512
%SES_LOWERCASE           = 1024
%SES_NOINPUTSEQUENCECHK  = 2048
%SES_BIDI                = 4096
%SES_SCROLLONKILLFOCUS   = 8192
%SES_XLTCRCRLFTOCR       = 16384
%SES_DRAFTMODE           = 32768

%SES_USECTF              = &H0010000
%SES_HIDEGRIDLINES       = &H0020000
%SES_USEATFONT           = &H0040000
%SES_CUSTOMLOOK          = &H0080000
%SES_LBSCROLLNOTIFY      = &H0100000
%SES_CTFALLOWEMBED       = &H0200000
%SES_CTFALLOWSMARTTAG    = &H0400000
%SES_CTFALLOWPROOFING    = &H0800000

'// Options for EM_SETLANGOPTIONS and EM_GETLANGOPTIONS
%IMF_AUTOKEYBOARD        = &H0001
%IMF_AUTOFONT            = &H0002
%IMF_IMECANCELCOMPLETE   = &H0004  ' high completes comp string when aborting, low cancels.
%IMF_IMEALWAYSSENDNOTIFY = &H0008
%IMF_AUTOFONTSIZEADJUST  = &H0010
%IMF_UIFONTS             = &H0020
%IMF_DUALFONT            = &H0080
%IMF_NORTFFONTSUBSTITUTE = &H0400

'// Values for EM_GETIMECOMPMODE
%ICM_NOTOPEN    = &H0000
%ICM_LEVEL3     = &H0001
%ICM_LEVEL2     = &H0002
%ICM_LEVEL2_5   = &H0003
%ICM_LEVEL2_SUI = &H0004
%ICM_CTF        = &H0005

'// Options for EM_SETTYPOGRAPHYOPTIONS
%TO_ADVANCEDTYPOGRAPHY   = 1
%TO_SIMPLELINEBREAK      = 2
%TO_DISABLECUSTOMTEXTOUT = 4
%TO_ADVANCEDLAYOUT       = 8

'// Pegasus outline mode messages (RE 3.0)

'// Outline mode message
%EM_OUTLINE      = %WM_USER + 220
'// Message for getting and restoring scroll pos
%EM_GETSCROLLPOS = %WM_USER + 221
%EM_SETSCROLLPOS = %WM_USER + 222
'// Change fontsize in current selection by wParam
%EM_SETFONTSIZE  = %WM_USER + 223
%EM_GETZOOM      = %WM_USER + 224
%EM_SETZOOM      = %WM_USER + 225
%EM_GETVIEWKIND  = %WM_USER + 226
%EM_SETVIEWKIND  = %WM_USER + 227

'// RichEdit 4.0 messages
%EM_GETPAGE          = %WM_USER + 228
%EM_SETPAGE          = %WM_USER + 229
%EM_GETHYPHENATEINFO = %WM_USER + 230
%EM_SETHYPHENATEINFO = %WM_USER + 231
%EM_GETPAGEROTATE    = %WM_USER + 235
%EM_SETPAGEROTATE    = %WM_USER + 236
%EM_GETCTFMODEBIAS   = %WM_USER + 237
%EM_SETCTFMODEBIAS   = %WM_USER + 238
%EM_GETCTFOPENSTATUS = %WM_USER + 240
%EM_SETCTFOPENSTATUS = %WM_USER + 241
%EM_GETIMECOMPTEXT   = %WM_USER + 242
%EM_ISIME            = %WM_USER + 243
%EM_GETIMEPROPERTY   = %WM_USER + 244

'// These messages control what rich edit does when it comes accross
'// OLE objects during RTF stream in.  Normally rich edit queries the client
'// application only after OleLoad has been called.  With these messages it is possible to
'// set the rich edit control to a mode where it will query the client application before
'// OleLoad is called
%EM_GETQUERYRTFOBJ   = %WM_USER + 269
%EM_SETQUERYRTFOBJ   = %WM_USER + 270

'// EM_SETPAGEROTATE wparam values
%EPR_0               = 0     ' // Text flows left to right and top to bottom
%EPR_270             = 1     ' // Text flows top to bottom and right to left
%EPR_180             = 2     ' // Text flows right to left and bottom to top
%EPR_90              = 3     ' // Text flows bottom to top and left to right

'// EM_SETCTFMODEBIAS wparam values
%CTFMODEBIAS_DEFAULT               = &H0000
%CTFMODEBIAS_FILENAME              = &H0001
%CTFMODEBIAS_NAME                  = &H0002
%CTFMODEBIAS_READING               = &H0003
%CTFMODEBIAS_DATETIME              = &H0004
%CTFMODEBIAS_CONVERSATION          = &H0005
%CTFMODEBIAS_NUMERIC               = &H0006
%CTFMODEBIAS_HIRAGANA              = &H0007
%CTFMODEBIAS_KATAKANA              = &H0008
%CTFMODEBIAS_HANGUL                = &H0009
%CTFMODEBIAS_HALFWIDTHKATAKANA     = &H000A
%CTFMODEBIAS_FULLWIDTHALPHANUMERIC = &H000B
%CTFMODEBIAS_HALFWIDTHALPHANUMERIC = &H000C

'// EM_SETIMEMODEBIAS lparam values
%IMF_SMODE_PLAURALCLAUSE = &H0001
%IMF_SMODE_NONE          = &H0002

'// EM_GETIMECOMPTEXT wparam structure
' // Size = 8 bytes
TYPE IMECOMPTEXT DWORD
   cb    AS LONG       ' // count of bytes in the output buffer.
   flags AS DWORD      ' // value specifying the composition string type.
                       ' // Currently only support ICT_RESULTREADSTR
END TYPE

%ICT_RESULTREADSTR      = 1

'// Outline mode wparam values
%EMO_EXIT               = 0      ' // Enter normal mode,  lparam ignored
%EMO_ENTER              = 1      ' // Enter outline mode, lparam ignored
%EMO_PROMOTE            = 2      ' // LOWORD(lparam) == 0 ==>
                                 '       //  promote  to body-text
                                 '       // LOWORD(lparam) != 0 ==>
                                 '       //  promote/demote current selection
                                 '       //  by indicated number of levels
%EMO_EXPAND             = 3      ' // HIWORD(lparam) = EMO_EXPANDSELECTION
                                 '       //  -> expands selection to level
                                 '       //  indicated in LOWORD(lparam)
                                 '       //  LOWORD(lparam) = -1/+1 corresponds
                                 '       //  to collapse/expand button presses
                                 '       //  in winword (other values are
                                 '       //  equivalent to having pressed these
                                 '       //  buttons more than once)
                                 '       //  HIWORD(lparam) = EMO_EXPANDDOCUMENT
                                 '       //  -> expands whole document to
                                 '       //  indicated level
%EMO_MOVESELECTION      = 4      ' // LOWORD(lparam) != 0 -> move current
                                 '       //  selection up/down by indicated amount
%EMO_GETVIEWMODE        = 5      ' // Returns VM_NORMAL or VM_OUTLINE

'// EMO_EXPAND options
%EMO_EXPANDSELECTION    = 0
%EMO_EXPANDDOCUMENT     = 1

%VM_NORMAL              = 4      ' // Agrees with RTF \viewkindN
%VM_OUTLINE             = 2
%VM_PAGE                = 9      ' // Screen page view (not print layout)

'// New notifications
%EN_MSGFILTER         = &H0700
%EN_REQUESTRESIZE     = &H0701
%EN_SELCHANGE         = &H0702
%EN_DROPFILES         = &H0703
%EN_PROTECTED         = &H0704
%EN_CORRECTTEXT       = &H0705  ' // PenWin specific
%EN_STOPNOUNDO        = &H0706
%EN_IMECHANGE         = &H0707  ' // East   Asia     specific
%EN_SAVECLIPBOARD     = &H0708
%EN_OLEOPFAILED       = &H0709
%EN_OBJECTPOSITIONS   = &H070a
%EN_LINK              = &H070b
%EN_DRAGDROPDONE      = &H070c
%EN_PARAGRAPHEXPANDED = &H070d
%EN_PAGECHANGE        = &H070e
%EN_LOWFIRTF          = &H070f
%EN_ALIGNLTR          = &H0710  ' // BiDi   specific notification
%EN_ALIGNRTL          = &H0711  ' // BiDi   specific notification

'// Event notification masks
%ENM_NONE              = &H00000000
%ENM_CHANGE            = &H00000001
%ENM_UPDATE            = &H00000002
%ENM_SCROLL            = &H00000004
%ENM_SCROLLEVENTS      = &H00000008
%ENM_DRAGDROPDONE      = &H00000010
%ENM_PARAGRAPHEXPANDED = &H00000020
%ENM_PAGECHANGE        = &H00000040
%ENM_KEYEVENTS         = &H00010000
%ENM_MOUSEEVENTS       = &H00020000
%ENM_REQUESTRESIZE     = &H00040000
%ENM_SELCHANGE         = &H00080000
%ENM_DROPFILES         = &H00100000
%ENM_PROTECTED         = &H00200000
%ENM_CORRECTTEXT       = &H00400000   ' // PenWin specific
%ENM_IMECHANGE         = &H00800000   ' // Used   by       RE1.0 compatibility
%ENM_LANGCHANGE        = &H01000000
%ENM_OBJECTPOSITIONS   = &H02000000
%ENM_LINK              = &H04000000
%ENM_LOWFIRTF          = &H08000000


'// New edit control styles
%ES_SAVESEL            = &H00008000
%ES_SUNKEN             = &H00004000
%ES_DISABLENOSCROLL    = &H00002000
'// Same as WS_MAXIMIZE, but that doesn't make sense so we re-use the value
%ES_SELECTIONBAR       = &H01000000
'// Same as ES_UPPERCASE, but re-used to completely disable OLE drag'n'drop
%ES_NOOLEDRAGDROP      = &H00000008

'// New edit control extended style
'#if (_WIN32_WINNT > 0x0400) || (WINVER > 0x0400)
%ES_EX_NOCALLOLEINIT   = &H00000000   ' // Not supported in RE 2.0/3.0
'#else
'#ifdef   _WIN32
'#define ES_EX_NOCALLOLEINIT      0x01000000
'#endif
'#endif

'// These flags are used in FE Windows
%ES_VERTICAL           = &H00400000   ' // Not supported in RE 2.0/3.0
%ES_NOIME              = &H00080000
%ES_SELFIME            = &H00040000

'// Edit control options
%ECO_AUTOWORDSELECTION = &H00000001
%ECO_AUTOVSCROLL       = &H00000040
%ECO_AUTOHSCROLL       = &H00000080
%ECO_NOHIDESEL         = &H00000100
%ECO_READONLY          = &H00000800
%ECO_WANTRETURN        = &H00001000
%ECO_SAVESEL           = &H00008000
%ECO_SELECTIONBAR      = &H01000000
%ECO_VERTICAL          = &H00400000    ' FE specific


'// ECO operations
%ECOOP_SET             = &H0001
%ECOOP_OR              = &H0002
%ECOOP_AND             = &H0003
%ECOOP_XOR             = &H0004

'// New word break function actions
%WB_CLASSIFY           = 3
%WB_MOVEWORDLEFT       = 4
%WB_MOVEWORDRIGHT      = 5
%WB_LEFTBREAK          = 6
%WB_RIGHTBREAK         = 7

'// East Asia specific flags
%WB_MOVEWORDPREV       = 4
%WB_MOVEWORDNEXT       = 5
%WB_PREVBREAK          = 6
%WB_NEXTBREAK          = 7

%PC_FOLLOWING          = 1
%PC_LEADING            = 2
%PC_OVERFLOW           = 3
%PC_DELIMITER          = 4
%WBF_WORDWRAP          = &H010
%WBF_WORDBREAK         = &H020
%WBF_OVERFLOW          = &H040
%WBF_LEVEL1            = &H080
%WBF_LEVEL2            = &H100
%WBF_CUSTOM            = &H200

'// East Asia specific flags
%IMF_FORCENONE         = &H0001
%IMF_FORCEENABLE       = &H0002
%IMF_FORCEDISABLE      = &H0004
%IMF_CLOSESTATUSWINDOW = &H0008
%IMF_VERTICAL          = &H0020
%IMF_FORCEACTIVE       = &H0040
%IMF_FORCEINACTIVE     = &H0080
%IMF_FORCEREMEMBER     = &H0100
%IMF_MULTIPLEEDIT      = &H0400

'// Word break flags (used with WB_CLASSIFY)
%WBF_CLASS             = &H0F?
%WBF_ISWHITE           = &H10?
%WBF_BREAKLINE         = &H20?
%WBF_BREAKAFTER        = &H40?


'// Data types

'#ifdef _WIN32
'// Extended edit word break proc (character set aware)
'typedef LONG (*EDITWORDBREAKPROCEX)(char *pchText, LONG cchText, BYTE bCharSet, INT action);
'#endif

'// All character format measurements are in twips
' // Size = 60 bytes
TYPE CHARFORMATA BYTE
   cbSize          AS DWORD                      ' UINT      cbSize
   dwMask          AS DWORD                      ' DWORD     dwMask
   dwEffects       AS DWORD                      ' DWORD     dwEffects
   yHeight         AS LONG                       ' LONG      yHeight
   yOffset         AS LONG                       ' LONG      yOffset
   crTextColor     AS DWORD                      ' COLORREF  crTextColor
   bCharSet        AS BYTE                       ' BYTE      bCharSet
   bPitchAndFamily AS BYTE                       ' BYTE      bPitchAndFamily
   szFaceName      AS ASCIIZ * %LF_FACESIZE      ' char      szFaceName[LF_FACESIZE]
   wFiller         AS WORD
END TYPE

' // Size = 92 bytes
TYPE CHARFORMATW BYTE
   cbSize          AS DWORD                      ' UINT      cbSize
   dwMask          AS DWORD                      ' DWORD     dwMask
   dwEffects       AS DWORD                      ' DWORD     dwEffects
   yHeight         AS LONG                       ' LONG      yHeight
   yOffset         AS LONG                       ' LONG      yOffset
   crTextColor     AS DWORD                      ' COLORREF  crTextColor
   bCharSet        AS BYTE                       ' BYTE      bCharSet
   bPitchAndFamily AS BYTE                       ' BYTE      bPitchAndFamily
   szFaceName      AS WSTRINGZ * %LF_FACESIZE    ' WCHAR     szFaceName[LF_FACESIZE]
   wFiller         AS WORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO CHARFORMAT = CHARFORMATW
#ELSE
   MACRO CHARFORMAT = CHARFORMATA
#ENDIF

' // Size = 84 bytes
TYPE CHARFORMAT2A BYTE
   cbSize          AS DWORD                      ' UINT      cbSize
   dwMask          AS DWORD                      ' DWORD     dwMask
   dwEffects       AS DWORD                      ' DWORD     dwEffects
   yHeight         AS LONG                       ' LONG      yHeight
   yOffset         AS LONG                       ' LONG      yOffset
   crTextColor     AS DWORD                      ' COLORREF  crTextColor
   bCharSet        AS BYTE                       ' BYTE      bCharSet
   bPitchAndFamily AS BYTE                       ' BYTE      bPitchAndFamily
   szFaceName      AS ASCIIZ * %LF_FACESIZE      ' char      szFaceName[LF_FACESIZE]
   wFiller         AS WORD                       ' To keep DWORD alignment
   wWeight         AS WORD                       ' WORD      wWeight // Font weight (LOGFONT value)
   sSpacing        AS INTEGER                    ' SHORT     sSpacing // Amount to space between letters
   crBackColor     AS DWORD                      ' COLORREF  crBackColor // Background color
   lcid            AS DWORD                      ' LCID      lcid // Locale ID
   dwReserved      AS DWORD                      ' DWORD     dwReserved // Reserved. Must be 0
   sStyle          AS INTEGER                    ' SHORT     sStyle // Style handle
   wKerning        AS WORD                       ' WORD      wKerning // Twip size above which to kern char pair
   bUnderlineType  AS BYTE                       ' BYTE      bUnderlineType // Underline type
   bAnimation      AS BYTE                       ' BYTE      bAnimation // Animated text like marching ants
   bRevAuthor      AS BYTE                       ' BYTE      bRevAuthor // Revision author index
   bReserved1      AS BYTE
END TYPE

' // Size = 116 bytes
TYPE CHARFORMAT2W BYTE
   cbSize          AS DWORD                      ' UINT      cbSize
   dwMask          AS DWORD                      ' DWORD     dwMask
   dwEffects       AS DWORD                      ' DWORD     dwEffects
   yHeight         AS LONG                       ' LONG      yHeight
   yOffset         AS LONG                       ' LONG      yOffset
   crTextColor     AS DWORD                      ' COLORREF  crTextColor
   bCharSet        AS BYTE                       ' BYTE      bCharSet
   bPitchAndFamily AS BYTE                       ' BYTE      bPitchAndFamily
   szFaceName      AS WSTRINGZ * %LF_FACESIZE    ' WCHAR     szFaceName[LF_FACESIZE]
   wFiller         AS WORD                       ' To keep DWORD alignment
   wWeight         AS WORD                       ' WORD      wWeight // Font weight (LOGFONT value)
   sSpacing        AS INTEGER                    ' SHORT     sSpacing // Amount to space between letters
   crBackColor     AS DWORD                      ' COLORREF  crBackColor // Background color
   lcid            AS DWORD                      ' LCID      lcid // Locale ID
   dwReserved      AS DWORD                      ' DWORD     dwReserved // Reserved. Must be 0
   sStyle          AS INTEGER                    ' SHORT     sStyle // Style handle
   wKerning        AS WORD                       ' WORD      wKerning // Twip size above which to kern char pair
   bUnderlineType  AS BYTE                       ' BYTE      bUnderlineType // Underline type
   bAnimation      AS BYTE                       ' BYTE      bAnimation // Animated text like marching ants
   bRevAuthor      AS BYTE                       ' BYTE      bRevAuthor // Revision author index
   bReserved1      AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO CHARFORMAT2 = CHARFORMAT2W
#ELSE
   MACRO CHARFORMAT2 = CHARFORMAT2A
#ENDIF

'// CFM_COLOR mirrors CFE_AUTOCOLOR, a little hack to easily deal with autocolor

'// CHARFORMAT masks
%CFM_BOLD      = &H00000001
%CFM_ITALIC    = &H00000002
%CFM_UNDERLINE = &H00000004
%CFM_STRIKEOUT = &H00000008
%CFM_PROTECTED = &H00000010
%CFM_LINK      = &H00000020    ' Exchange hyperlink extension
%CFM_SIZE      = &H80000000???
%CFM_COLOR     = &H40000000
%CFM_FACE      = &H20000000
%CFM_OFFSET    = &H10000000
%CFM_CHARSET   = &H08000000

'// CHARFORMAT effects
%CFE_BOLD      = &H0001
%CFE_ITALIC    = &H0002
%CFE_UNDERLINE = &H0004
%CFE_STRIKEOUT = &H0008
%CFE_PROTECTED = &H0010
%CFE_LINK      = &H0020
%CFE_AUTOCOLOR = &H40000000 ' NOTE: this corresponds to CFM_COLOR, which controls it

'// Masks and effects defined for CHARFORMAT2 -- an (*) indicates
'// that the data is stored by RichEdit 2.0/3.0, but not displayed

%CFM_SMALLCAPS      = &H0040         ' // (*)
%CFM_ALLCAPS        = &H0080         ' // Displayed by 3.0
%CFM_HIDDEN         = &H0100         ' // Hidden by 3.0
%CFM_OUTLINE        = &H0200         ' // (*)
%CFM_SHADOW         = &H0400         ' // (*)
%CFM_EMBOSS         = &H0800         ' // (*)
%CFM_IMPRINT        = &H1000         ' // (*)
%CFM_DISABLED       = &H2000
%CFM_REVISED        = &H4000

%CFM_BACKCOLOR      = &H04000000
%CFM_LCID           = &H02000000
%CFM_UNDERLINETYPE  = &H00800000     ' // Many displayed by 3.0
%CFM_WEIGHT         = &H00400000
%CFM_SPACING        = &H00200000     ' // Displayed by 3.0
%CFM_KERNING        = &H00100000     ' // (*)
%CFM_STYLE          = &H00080000     ' // (*)
%CFM_ANIMATION      = &H00040000     ' // (*)
%CFM_REVAUTHOR      = &H00008000

%CFE_SUBSCRIPT      = &H00010000     ' // Superscript and subscript are
%CFE_SUPERSCRIPT    = &H00020000     ' //  mutually exclusive

%CFM_SUBSCRIPT      = %CFE_SUBSCRIPT OR %CFE_SUPERSCRIPT
%CFM_SUPERSCRIPT    = %CFM_SUBSCRIPT

'// CHARFORMAT "ALL" masks
%CFM_EFFECTS = %CFM_BOLD OR %CFM_ITALIC OR %CFM_UNDERLINE OR %CFM_COLOR OR _
               %CFM_STRIKEOUT OR %CFE_PROTECTED OR %CFM_LINK
%CFM_ALL = %CFM_EFFECTS OR %CFM_SIZE OR %CFM_FACE OR %CFM_OFFSET OR %CFM_CHARSET

%CFM_EFFECTS2 = %CFM_EFFECTS OR %CFM_DISABLED OR %CFM_SMALLCAPS OR %CFM_ALLCAPS OR _
                %CFM_HIDDEN  OR %CFM_OUTLINE OR %CFM_SHADOW OR %CFM_EMBOSS OR _
                %CFM_IMPRINT OR %CFM_DISABLED OR %CFM_REVISED OR _
                %CFM_SUBSCRIPT OR %CFM_SUPERSCRIPT OR %CFM_BACKCOLOR

%CFM_ALL2 = %CFM_ALL OR %CFM_EFFECTS2 OR %CFM_BACKCOLOR OR %CFM_LCID OR _
             %CFM_UNDERLINETYPE OR %CFM_WEIGHT OR %CFM_REVAUTHOR OR _
             %CFM_SPACING OR %CFM_KERNING OR %CFM_STYLE OR %CFM_ANIMATION

%CFE_SMALLCAPS      = %CFM_SMALLCAPS
%CFE_ALLCAPS        = %CFM_ALLCAPS
%CFE_HIDDEN         = %CFM_HIDDEN
%CFE_OUTLINE        = %CFM_OUTLINE
%CFE_SHADOW         = %CFM_SHADOW
%CFE_EMBOSS         = %CFM_EMBOSS
%CFE_IMPRINT        = %CFM_IMPRINT
%CFE_DISABLED       = %CFM_DISABLED
%CFE_REVISED        = %CFM_REVISED

'// CFE_AUTOCOLOR and CFE_AUTOBACKCOLOR correspond to CFM_COLOR and
'// CFM_BACKCOLOR, respectively, which control them
%CFE_AUTOBACKCOLOR  = %CFM_BACKCOLOR

'// Underline types. RE 1.0 displays only CFU_UNDERLINE
%CFU_CF1UNDERLINE             = &HFF   ' // Map charformat's bit underline to CF2
%CFU_INVERT                   = &HFE   ' // For IME composition fake a selection
%CFU_UNDERLINETHICKLONGDASH   = 18     ' // (*) display as dash
%CFU_UNDERLINETHICKDOTTED     = 17     ' // (*) display as dot
%CFU_UNDERLINETHICKDASHDOTDOT = 16     ' // (*) display as dash dot dot
%CFU_UNDERLINETHICKDASHDOT    = 15     ' // (*) display as dash dot
%CFU_UNDERLINETHICKDASH       = 14     ' // (*) display as dash
%CFU_UNDERLINELONGDASH        = 13     ' // (*) display as dash
%CFU_UNDERLINEHEAVYWAVE       = 12     ' // (*) display as wave
%CFU_UNDERLINEDOUBLEWAVE      = 11     ' // (*) display as wave
%CFU_UNDERLINEHAIRLINE        = 10     ' // (*) display as single
%CFU_UNDERLINETHICK           = 9
%CFU_UNDERLINEWAVE            = 8
%CFU_UNDERLINEDASHDOTDOT      = 7
%CFU_UNDERLINEDASHDOT         = 6
%CFU_UNDERLINEDASH            = 5
%CFU_UNDERLINEDOTTED          = 4
%CFU_UNDERLINEDOUBLE          = 3      ' // (*) display as single
%CFU_UNDERLINEWORD            = 2      ' // (*) display as single
%CFU_UNDERLINE                = 1
%CFU_UNDERLINENONE            = 0

%yHeightCharPtsMost = 1638

'// EM_SETCHARFORMAT wParam masks
%SCF_SELECTION      = &H0001
%SCF_WORD           = &H0002
%SCF_DEFAULT        = &H0000   ' // Set default charformat or paraformat
%SCF_ALL            = &H0004   ' // Not valid with SCF_SELECTION or SCF_WORD
%SCF_USEUIRULES     = &H0008   ' // Modifier for SCF_SELECTION; says that
                               ' //  format came from a toolbar, etc., and
                               ' //  hence UI formatting rules should be
                               ' //  used instead of literal formatting
%SCF_ASSOCIATEFONT  = &H0010   ' // Associate fontname with bCharSet (one
                               ' //  possible for each of Western, ME, FE,
                               ' //  Thai)
%SCF_NOKBUPDATE     = &H0020   ' // Do not update KB layput for this change
                               ' //  even if autokeyboard is on
%SCF_ASSOCIATEFONT2 = &H0040   ' // Associate plane-2 (surrogate) font

' // Size = 8 bytes
TYPE CHARRANGE DWORD
   cpMin AS LONG   ' LONG   cpMin
   cpMax AS LONG   ' LONG   cpMax
END TYPE

' // Size = 12 bytes
TYPE TEXTRANGEA DWORD
   chrg      AS CHARRANGE   ' CHARRANGE chrg
   lpstrText AS ASCIIZ PTR  ' LPSTR lpstrText  // Allocated by caller, zero terminated by RichEdit
END TYPE

' // Size = 12 bytes
TYPE TEXTRANGEW DWORD
   chrg      AS CHARRANGE       ' CHARRANGE chrg
   lpstrText AS WSTRINGZ PTR    ' LPWSTR lpstrText  // Allocated by caller, zero terminated by RichEdit
END TYPE

#IF %DEF(%UNICODE)
   MACRO TEXTRANGE = TEXTRANGEW
#ELSE
   MACRO TEXTRANGE = TEXTRANGEA
#ENDIF

'typedef DWORD (CALLBACK *EDITSTREAMCALLBACK)(DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb);

' // Size = 12 bytes
TYPE EDITSTREAM DWORD
   dwCookie    AS DWORD   ' // User value passed to callback as first parameter
   dwError     AS DWORD   ' // Last error
   pfnCallback AS DWORD
END TYPE

'// Stream formats. Flags are all in low word, since high word
'// gives possible codepage choice.
%SF_TEXT           = &H0001
%SF_RTF            = &H0002
%SF_RTFNOOBJS      = &H0003    ' // Write only
%SF_TEXTIZED       = &H0004    ' // Write only

%SF_UNICODE        = &H0010    ' // Unicode file (UCS2 little endian)
%SF_USECODEPAGE    = &H0020    ' // CodePage given by high word
%SF_NCRFORNONASCII = &H40      ' // Output /uN for nonASCII
%SFF_WRITEXTRAPAR  = &H80      ' // Output \par at end

'// Flag telling stream operations to operate on selection only
'// EM_STREAMIN  replaces current selection
'// EM_STREAMOUT streams out current selection
%SFF_SELECTION     = &H8000??

'// Flag telling stream operations to ignore some FE control words
'// having to do with FE word breaking and horiz vs vertical text.
'// Not used in RichEdit 2.0 and later
%SFF_PLAINRTF      = &H4000??

'// Flag telling file stream output (SFF_SELECTION flag not set) to persist
'// \viewscaleN control word.
%SFF_PERSISTVIEWSCALE = &H2000??

'// Flag telling file stream input with SFF_SELECTION flag not set not to
'// close the document
%SFF_KEEPDOCINFO   = &H1000??

'// Flag telling stream operations to output in Pocket Word format
%SFF_PWD           = &H0800??

'// 3-bit field specifying the value of N - 1 to use for \rtfN or \pwdN
%SF_RTFVAL         = &H0700??

' // Size = 12 bytes
TYPE FINDTEXT_A DWORD
   chrg      AS CHARRANGE    ' CHARRANGE chrg
   lpstrText AS ASCIIZ PTR   ' LPCSTR lpstrText
END TYPE

' // Size = 12 bytes
TYPE FINDTEXT_W DWORD
   chrg      AS CHARRANGE      ' CHARRANGE chrg
   lpstrText AS WSTRINGZ PTR   ' LPCWSTR lpstrText
END TYPE

MACRO FINDTEXTAPIA = FINDTEXT_A
MACRO tagFINDTEXTA = FINDTEXT_A
MACRO FINDTEXTAPIW = FINDTEXT_W
MACRO tagFINDTEXTW = FINDTEXT_W
' // For compatibility with the PB includes
MACRO FINDTEXTA_TYPE = FINDTEXT_A
MACRO FINDTEXTW_TYPE = FINDTEXT_W

#IF %DEF(%UNICODE)
   MACRO FINDTEXTAPI = FINDTEXT_W
   MACRO tagFINDTEXT = FINDTEXT_W
   ' // For compatibility with the PB includes
   MACRO FINDTEXT_TYPE = FINDTEXT_W
#ELSE
   MACRO FINDTEXTAPI = FINDTEXT_A
   MACRO tagFINDTEXT = FINDTEXT_A
   ' // For compatibility with the PB includes
   MACRO FINDTEXT_TYPE = FINDTEXT_A
#ENDIF

' // Size = 20 bytes
TYPE FINDTEXTEXA DWORD
   chrg      AS CHARRANGE    ' CHARRANGE chrg
   lpstrText AS ASCIIZ PTR   ' LPCSTR    lpstrText
   chrgText  AS CHARRANGE    ' CHARRANGE chrgText
END TYPE

' // Size = 20 bytes
TYPE FINDTEXTEXW DWORD
   chrg      AS CHARRANGE      ' CHARRANGE chrg
   lpstrText AS WSTRINGZ PTR   ' LPCWSTR   lpstrText
   chrgText  AS CHARRANGE      ' CHARRANGE chrgText
END TYPE

#IF %DEF(%UNICODE)
   MACRO FINDTEXTEX = FINDTEXTEXW
#ELSE
   MACRO FINDTEXTEX = FINDTEXTEXA
#ENDIF

' // Size = 48 bytes
TYPE FORMATRANGE DWORD
   hdc       AS DWORD       ' HDC hdc
   hdcTarget AS DWORD       ' HDC hdcTarget
   rc        AS RECT        ' RECT rc
   rcPage    AS RECT        ' RECT rcPage
   chrg      AS CHARRANGE   ' CHARRANGE chrg
END TYPE

'// All paragraph measurements are in twips

%MAX_TAB_STOPS   = 32
%lDefaultTab     = 720
%MAX_TABLE_CELLS = 63

'// This is a hack to make PARAFORMAT compatible with RE 1.0
'#define   wReserved   wEffects

' // Size = 156 bytes
TYPE PARAFORMAT DWORD FILL
   cbSize        AS DWORD     ' UINT   cbSize
   dwMask        AS DWORD     ' DWORD  dwMask
   wNumbering    AS WORD      ' WORD   wNumbering
   wEffects      AS WORD      ' WORD   wEffects
   dxStartIndent AS LONG      ' LONG   dxStartIndent
   dxRightIndent AS LONG      ' LONG   dxRightIndent
   dxOffset      AS LONG      ' LONG   dxOffset
   wAlignment    AS WORD      ' WORD   wAlignment
   cTabCount     AS INTEGER   ' SHORT  cTabCount
   rgxTabs(%MAX_TAB_STOPS - 1) AS LONG
END TYPE

' // Size = 188 bytes
TYPE PARAFORMAT2 DWORD FILL
   cbSize           AS DWORD     ' UINT   cbSize
   dwMask           AS DWORD     ' DWORD  dwMask
   wNumbering       AS WORD      ' WORD   wNumbering
   wEffects         AS WORD      ' WORD   wEffects
   dxStartIndent    AS LONG      ' LONG   dxStartIndent
   dxRightIndent    AS LONG      ' LONG   dxRightIndent
   dxOffset         AS LONG      ' LONG   dxOffset
   wAlignment       AS WORD      ' WORD   wAlignment
   cTabCount        AS INTEGER   ' SHORT  cTabCount
   rgxTabs(%MAX_TAB_STOPS - 1) AS LONG
   dySpaceBefore    AS LONG      ' LONG   dySpaceBefore     // Vertical spacing before para
   dySpaceAfter     AS LONG      ' LONG   dySpaceAfter      // Vertical spacing after para
   dyLineSpacing    AS LONG      ' LONG   dyLineSpacing     // Line spacing depending on Rule
   sStyle           AS INTEGER   ' SHORT  sStyle            // Style handle
   bLineSpacingRule AS BYTE      ' BYTE   bLineSpacingRule  // Rule for line spacing (see tom.doc)
   bOutlineLevel    AS BYTE      ' BYTE   bOutlineLevel     // Outline Level
   wShadingWeight   AS WORD      ' WORD   wShadingWeight    // Shading in hundredths of a per cent
   wShadingStyle    AS WORD      ' WORD   wShadingStyle     // Byte 0: style, nib 2: cfpat, 3: cbpat
   wNumberingStart  AS WORD      ' WORD   wNumberingStart   // Starting value for numbering
   wNumberingStyle  AS WORD      ' WORD   wNumberingStyle   // Alignment, Roman/Arabic, (), ), ., etc.
   wNumberingTab    AS WORD      ' WORD   wNumberingTab     // Space bet 1st indent and 1st-line text
   wBorderSpace     AS WORD      ' WORD   wBorderSpace      // Border-text spaces (nbl/bdr in pts)
   wBorderWidth     AS WORD      ' WORD   wBorderWidth      // Pen widths (nbl/bdr in half twips)
   wBorders         AS WORD      ' WORD   wBorders          // Border styles (nibble/border)
END TYPE


'// PARAFORMAT mask values
%PFM_STARTINDENT       = &H00000001
%PFM_RIGHTINDENT       = &H00000002
%PFM_OFFSET            = &H00000004
%PFM_ALIGNMENT         = &H00000008
%PFM_TABSTOPS          = &H00000010
%PFM_NUMBERING         = &H00000020
%PFM_OFFSETINDENT      = &H80000000???

'// PARAFORMAT 2.0 masks and effects
%PFM_SPACEBEFORE       = &H00000040
%PFM_SPACEAFTER        = &H00000080
%PFM_LINESPACING       = &H00000100
%PFM_STYLE             = &H00000400
%PFM_BORDER            = &H00000800   ' // (*)
%PFM_SHADING           = &H00001000   ' // (*)
%PFM_NUMBERINGSTYLE    = &H00002000   ' // RE 3.0
%PFM_NUMBERINGTAB      = &H00004000   ' // RE 3.0
%PFM_NUMBERINGSTART    = &H00008000   ' // RE 3.0

%PFM_RTLPARA           = &H00010000
%PFM_KEEP              = &H00020000   ' // (*)
%PFM_KEEPNEXT          = &H00040000   ' // (*)
%PFM_PAGEBREAKBEFORE   = &H00080000   ' // (*)
%PFM_NOLINENUMBER      = &H00100000   ' // (*)
%PFM_NOWIDOWCONTROL    = &H00200000   ' // (*)
%PFM_DONOTHYPHEN       = &H00400000   ' // (*)
%PFM_SIDEBYSIDE        = &H00800000   ' // (*)
%PFM_TABLE             = &H40000000   ' // RE 3.0
%PFM_TEXTWRAPPINGBREAK = &H20000000   ' // RE 3.0
%PFM_TABLEROWDELIMITER = &H10000000   ' // RE 4.0

'' // The following three properties are read only
%PFM_COLLAPSED         = &H01000000   ' // RE 3.0
%PFM_OUTLINELEVEL      = &H02000000   ' // RE 3.0
%PFM_BOX               = &H04000000   ' // RE 3.0
%PFM_RESERVED2         = &H08000000   ' // RE 4.0


'// PARAFORMAT "ALL" masks
%PFM_ALL = %PFM_STARTINDENT OR %PFM_RIGHTINDENT OR %PFM_OFFSET OR _
           %PFM_ALIGNMENT OR %PFM_TABSTOPS OR %PFM_NUMBERING OR _
           %PFM_OFFSETINDENT OR %PFM_RTLPARA

'// Note: PARAFORMAT has no effects (BiDi RichEdit 1.0 does have PFE_RTLPARA)
%PFM_EFFECTS = %PFM_RTLPARA OR %PFM_KEEP OR %PFM_KEEPNEXT OR %PFM_TABLE OR _
               %PFM_PAGEBREAKBEFORE OR %PFM_NOLINENUMBER OR _
               %PFM_NOWIDOWCONTROL OR %PFM_DONOTHYPHEN OR %PFM_SIDEBYSIDE OR _
               %PFM_TABLE OR %PFM_TABLEROWDELIMITER

%PFM_ALL2 = %PFM_ALL OR %PFM_EFFECTS OR %PFM_SPACEBEFORE OR %PFM_SPACEAFTER OR _
            %PFM_LINESPACING OR %PFM_STYLE OR %PFM_SHADING OR %PFM_BORDER OR _
            %PFM_NUMBERINGTAB OR %PFM_NUMBERINGSTART OR %PFM_NUMBERINGSTYLE

%PFE_RTLPARA           = &H00000001   ' (PFM_RTLPARA          >> 16)
%PFE_KEEP              = &H00000002   ' (PFM_KEEP             >> 16)   // (*)
%PFE_KEEPNEXT          = &H00000004   ' (PFM_KEEPNEXT         >> 16)   // (*)
%PFE_PAGEBREAKBEFORE   = &H00000008   ' (PFM_PAGEBREAKBEFORE  >> 16)   // (*)
%PFE_NOLINENUMBER      = &H00000010   ' (PFM_NOLINENUMBER     >> 16)   // (*)
%PFE_NOWIDOWCONTROL    = &H00000020   ' (PFM_NOWIDOWCONTROL   >> 16)   // (*)
%PFE_DONOTHYPHEN       = &H00000040   ' (PFM_DONOTHYPHEN      >> 16)   // (*)
%PFE_SIDEBYSIDE        = &H00000080   ' (PFM_SIDEBYSIDE       >> 16)   // (*)
%PFE_TEXTWRAPPINGBREAK = &H00004000   ' (PFM_TEXTWRAPPINGBREAK>> 16)   // (*)

'// The following four effects are read only
%PFE_COLLAPSED         = &H00000100   ' (PFM_COLLAPSED        >> 16)   // (+)
%PFE_BOX               = &H00000400   ' (PFM_BOX              >> 16)   // (+)
%PFE_TABLE             = &H00004000   ' (PFM_TABLE            >> 16)   // Inside table row. RE 3.0
%PFE_TABLEROWDELIMITER = &H00001000   ' (PFM_TABLEROWDELIMITER>> 16)   // Table row start. RE 4.0

'// PARAFORMAT numbering options
%PFN_BULLET      = 1     ' // tomListBullet

'// PARAFORMAT2 wNumbering options
%PFN_ARABIC      = 2     ' // tomListNumberAsArabic:   0, 1, 2,   ...
%PFN_LCLETTER    = 3     ' // tomListNumberAsLCLetter: a, b, c,   ...
%PFN_UCLETTER    = 4     ' // tomListNumberAsUCLetter: A, B, C,   ...
%PFN_LCROMAN     = 5     ' // tomListNumberAsLCRoman:  i, ii, iii,   ...
%PFN_UCROMAN     = 6     ' // tomListNumberAsUCRoman:  I, II, III,   ...

'// PARAFORMAT2 wNumberingStyle options
%PFNS_PAREN      = &H000  ' // default, e.g.,              1)
%PFNS_PARENS     = &H100  ' // tomListParentheses/256, e.g., (1)
%PFNS_PERIOD     = &H200  ' // tomListPeriod/256, e.g.,        1.
%PFNS_PLAIN      = &H300  ' // tomListPlain/256, e.g.,        1
%PFNS_NONUMBER   = &H400  ' // Used for continuation w/o number

%PFNS_NEWNUMBER  = &H8000?? ' // Start new number with wNumberingStart
                            ' // (can be combined with other PFNS_xxx)
'// PARAFORMAT alignment options
%PFA_LEFT        = 1
%PFA_RIGHT       = 2
%PFA_CENTER      = 3

'// PARAFORMAT2 alignment options
%PFA_JUSTIFY          = 4  ' // New paragraph-alignment option 2.0 (*)
%PFA_FULL_INTERWORD   = 4  ' // These are supported in 3.0 with advanced
%PFA_FULL_INTERLETTER = 5  ' //  typography enabled
%PFA_FULL_SCALED      = 6
%PFA_FULL_GLYPHS      = 7
%PFA_SNAP_GRID        = 8


'// Notification structures
#IF NOT %DEF(%WM_NOTIFY)
    %WM_NOTIFY = &H004E

' // Size = 12 bytes
' // Note: NMHDR is built-in in PB
' // code should be DWORD, but it is defined as LONG in PBWin 9 built-in structure
TYPE NMHDR   ' DWORD
   hwndFrom AS DWORD   ' HWND   hwndFrom
   idFrom   AS DWORD   ' UINT   idFrom
   code     AS LONG    ' UINT   code
END TYPE
#ENDIF   ' // !WM_NOTIFY

' // Size = 24 bytes
UNION MSGFILTER_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE MSGFILTER DWORD
   MSGFILTER_UNION   ' NMHDR  nmhdr
   msg    AS DWORD   ' UINT   msg
   wParam AS DWORD   ' WPARAM wParam
   lParam AS LONG    ' LPARAM lParam
END TYPE

' // Size = 28 bytes
UNION REQRESIZE_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE REQRESIZE DWORD
   REQRESIZE_UNION ' NMHDR nmhdr
   rc    AS RECT   ' RECT  rc
END TYPE

' // Size = 24 bytes
UNION SELCHANGE_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE SELCHANGE DWORD FILL
   SELCHANGE_UNION        ' NMHDR     nmhdr
   chrg    AS CHARRANGE   ' CHARRANGE chrg
   seltyp  AS WORD        ' WORD      seltyp
   wFiller AS WORD
END TYPE

%SEL_EMPTY       = &H0000
%SEL_TEXT        = &H0001
%SEL_OBJECT      = &H0002
%SEL_MULTICHAR   = &H0004
%SEL_MULTIOBJECT = &H0008

'// Used with IRichEditOleCallback::GetContextMenu, this flag will be
'// passed as a "selection type".  It indicates that a context menu for
'// a right-mouse drag drop should be generated.  The IOleObject parameter
'// will really be the IDataObject for the drop
%GCM_RIGHTMOUSEDROP = &H8000??

' // Size = 24 bytes
UNION ENDROPFILES_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE ENDROPFILES DWORD
   ENDROPFILES_UNION     ' NMHDR  nmhdr
   hDrop      AS DWORD   ' HANDLE hDrop
   cp         AS LONG    ' LONG   cp
   fProtected AS LONG    ' BOOL   fProtected
END TYPE

' // Size = 32 bytes
UNION ENPROTECTED_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE ENPROTECTED DWORD
   ENPROTECTED_UNION     ' NMHDR     nmhdr
   msg    AS DWORD       ' UINT      msg
   wParam AS DWORD       ' WPARAM    wParam
   lParam AS LONG        ' LPARAM    lParam
   chrg   AS CHARRANGE   ' CHARRANGE chrg
END TYPE

' // Size = 20 bytes
UNION ENSAVECLIPBOARD_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE ENSAVECLIPBOARD DWORD
   ENSAVECLIPBOARD_UNION   ' NMHDR nmhdr
   cObjectCount AS LONG    ' LONG  cObjectCount
   cch          AS LONG    ' LONG  cch
END TYPE

' // Size = 24 bytes
UNION ENOLEOPFAILED_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE ENOLEOPFAILED DWORD
   ENOLEOPFAILED_UNION   ' NMHDR   nmhdr
   iob   AS LONG         ' LONG    iob
   lOper AS LONG         ' LONG    lOper
   hr    AS LONG         ' HRESULT hr
END TYPE

%OLEOP_DOVERB  = 1

' // Size = 20 bytes
UNION OBJECTPOSITIONS_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE OBJECTPOSITIONS DWORD
   OBJECTPOSITIONS_UNION      ' NMHDR nmhdr
   cObjectCount AS LONG       ' LONG  cObjectCount
   pcpPositions AS LONG PTR   ' LONG *pcpPositions
END TYPE

' // Size = 32 bytes
UNION ENLINK_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE ENLINK DWORD
   ENLINK_UNION          ' NMHDR     nmhdr
   msg    AS DWORD       ' UINT      msg
   wParam AS DWORD       ' WPARAM    wParam
   lParam AS LONG        ' LPARAM    lParam
   chrg   AS CHARRANGE   ' CHARRANGE chrg
END TYPE

' // Size = 16 bytes
UNION ENLOWFIRTF_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE ENLOWFIRTF DWORD
   ENLOWFIRTF_UNION          ' NMHDR nmhdr
   szControl AS ASCIIZ PTR   ' char *szControl
END TYPE


'// PenWin specific
' // Size = 24 bytes
UNION ENCORRECTTEXT_UNION   ' // To allow to use both hdr and nmhdr
   hdr    AS NMHDR   ' NMHDR  nmhdr
   nmhdr  AS NMHDR   ' NMHDR  nmhdr
END UNION

TYPE ENCORRECTTEXT DWORD FILL
   ENCORRECTTEXT_UNION    ' NMHDR     nmhdr
   chrg    AS CHARRANGE   ' CHARRANGE chrg
   seltyp  AS WORD        ' WORD      seltyp
   wFiller AS WORD
END TYPE

'// East Asia specific
' // Size = 8 bytes
TYPE PUNCTUATION DWORD
   iSize         AS DWORD        ' UINT  iSize
   szPunctuation AS ASCIIZ PTR   ' LPSTR szPunctuation
END TYPE

'// East Asia specific
' // Size = 12 bytes
TYPE COMPCOLOR DWORD
   crText       AS DWORD   ' COLORREF crText
   crBackground AS DWORD   ' COLORREF crBackground
   dwEffects    AS DWORD   ' DWORD    dwEffects
END TYPE

'// Clipboard formats - use as parameter to RegisterClipboardFormat()
'#define CF_RTF          TEXT("Rich Text Format")
'#define CF_RTFNOOBJS    TEXT("Rich Text Format Without Objects")
'#define CF_RETEXTOBJ    TEXT("RichEdit Text and Objects")

$CF_RTF       = "Rich Text Format"
$CF_RTFNOOBJS = "Rich Text Format Without Objects"
$CF_RETEXTOBJ = "RichEdit Text and Objects"

$$CF_RTF       = "Rich Text Format"$$
$$CF_RTFNOOBJS = "Rich Text Format Without Objects"$$
$$CF_RETEXTOBJ = "RichEdit Text and Objects"$$

#IF %DEF(%UNICODE)
   MACRO CF_RTF = $$CF_RTF
   MACRO CF_RTFNOOBJS = $$CF_RTFNOOBJS
   MACRO CF_RETEXTOBJ = $$CF_RETEXTOBJ
#ELSE
   MACRO CF_RTF = $CF_RTF
   MACRO CF_RTFNOOBJS = $CF_RTFNOOBJS
   MACRO CF_RETEXTOBJ = $CF_RETEXTOBJ
#ENDIF

'// Paste Special
' // Size = 8 bytes
TYPE REPASTESPECIAL DWORD
   dwAspect AS DWORD   ' DWORD     dwAspect
   dwParam  AS DWORD   ' DWORD_PTR dwParam
END TYPE

'//   UndoName info
' UNDONAMEID enum
%UID_UNKNOWN     = 0
%UID_TYPING      = 1
%UID_DELETE      = 2
%UID_DRAGDROP    = 3
%UID_CUT         = 4
%UID_PASTE       = 5
%UID_AUTOCORRECT = 6

'// Flags for the SETEXTEX data structure
%ST_DEFAULT   = 0
%ST_KEEPUNDO  = 1
%ST_SELECTION = 2
%ST_NEWCHARS  = 4

'// EM_SETTEXTEX info; this struct is passed in the wparam of the message
' // Size = 8 bytes
TYPE SETTEXTEX DWORD
   flags    AS DWORD   ' DWORD flags    // Flags (see the ST_XXX defines
   codepage AS DWORD   ' UINT  codepage // Code page for translation (CP_ACP for sys default;
                       '                   1200 for Unicode, -1 for control default
END TYPE

'// Flags for the GETEXTEX data structure
%GT_DEFAULT      = 0
%GT_USECRLF      = 1
%GT_SELECTION    = 2
%GT_RAWTEXT      = 4
%GT_NOHIDDENTEXT = 8

'// EM_GETTEXTEX info; this struct is passed in the wparam of the message
' // Size = 20 bytes
TYPE GETTEXTEX DWORD
   cb            AS DWORD        ' DWORD cb  // Count of bytes in the string
   flags         AS DWORD        ' DWORD flags  // Flags (see the GT_XXX defines
   codepage      AS DWORD        ' UINT codepage  // Code page for translation (CP_ACP for sys default,
                                 ' 1200 for Unicode, -1 for control default
   lpDefaultChar AS ASCIIZ PTR   ' LPCSTR lpUsedDefChar  // Replacement for unmappable chars
   lpUsedDefChar AS LONG PTR     ' LPBOOL lpUsedDefChar  // Pointer to flag set when def char used
END TYPE

'// Flags for the GETTEXTLENGTHEX data structure
%GTL_DEFAULT  = 0    ' // Do the default (return # of chars)
%GTL_USECRLF  = 1    ' // Compute answer using CRLFs for paragraphs
%GTL_PRECISE  = 2    ' // Compute a precise answer
%GTL_CLOSE    = 4    ' // Fast computation of a "close" answer
%GTL_NUMCHARS = 8    ' // Return the number of characters
%GTL_NUMBYTES = 16   ' // Return the number of _bytes_

'// EM_GETTEXTLENGTHEX info; this struct is passed in the wparam of the msg
' // Size = 8 bytes
TYPE GETTEXTLENGTHEX DWORD
   flags    AS DWORD    ' DWORD flags    // Flags (see GTL_XXX defines)
   codepage AS DWORD    ' UINT codepage  // Code page for translation (CP_ACP for default,
                        '                   1200 for Unicode
END TYPE

'// BiDi specific features
' // Size = 8 bytes
TYPE BIDIOPTIONS DWORD FILL
   cbSize   AS DWORD
   wMask    AS WORD
   wEffects AS WORD
END TYPE

'// BIDIOPTIONS masks
#IF %RICHEDIT_VER = &H0100
%BOM_DEFPARADIR       = &H0001  ' // Default paragraph direction (implies alignment) (obsolete)
%BOM_PLAINTEXT        = &H0002  ' // Use plain text layout (obsolete)
#ENDIF    ' // _RICHEDIT_VER == 0x0100
%BOM_NEUTRALOVERRIDE  = &H0004  ' // Override neutral layout (obsolete)
%BOM_CONTEXTREADING   = &H0008  ' // Context reading order
%BOM_CONTEXTALIGNMENT = &H0010  ' // Context alignment


'// BIDIOPTIONS effects
#IF %RICHEDIT_VER = &H0100
%BOE_RTLDIR           = &H0001  ' // Default paragraph direction (implies alignment) (obsolete)
%BOE_PLAINTEXT        = &H0002  ' // Use plain text layout (obsolete)
#ENDIF   ' // _RICHEDIT_VER == 0x0100
%BOE_NEUTRALOVERRIDE  = &H0004  ' // Override neutral layout (obsolete)
%BOE_CONTEXTREADING   = &H0008  ' // Context reading order
%BOE_CONTEXTALIGNMENT = &H0010  ' // Context alignment
%BOE_LEGACYBIDICLASS  = &H0040  ' // Legacy Bidi classification

'// Additional EM_FINDTEXT[EX] flags
%FR_MATCHDIAC      = &H20000000???
%FR_MATCHKASHIDA   = &H40000000???
%FR_MATCHALEFHAMZA = &H80000000???

'// UNICODE embedding character
#IF NOT %DEF(%WCH_EMBEDDING)
'#define WCH_EMBEDDING (WCHAR)0xFFFC
%WCH_EMBEDDING = &HFFFC
#ENDIF   ' // WCH_EMBEDDING

'// khyph - Kind of hyphenation
'KHYPH enum
%khyphNil          = 0   ' // No Hyphenation
%khyphNormal       = 1   ' // Normal Hyphenation
%khyphAddBefore    = 2   ' // Add letter before hyphen
%khyphChangeBefore = 3   ' // Change letter before hyphen
%khyphDeleteBefore = 4   ' // Delete letter before hyphen
%khyphChangeAfter  = 5   ' // Change letter after hyphen
%khyphDelAndChange = 6   ' // Delete letter before hyphen and change
                         ' //  letter preceding hyphen

' // Size = 12 bytes
TYPE HYPHRESULT
   khyph   AS LONG           ' KHYPH khyph    // Kind of hyphenation
   ichHyph AS LONG           ' long  ichHyph  // Character which was hyphenated
   chHyph  AS WORD           ' WCHAR chHyph   // Depending on hyphenation type, character added, changed, etc.
   wFiller AS WORD
END TYPE

'void WINAPI HyphenateProc(__in WCHAR *pszWord, LANGID langid, long ichExceed, HYPHRESULT *phyphresult);
'SUB HyphenateProc (BYVAL pszWord AS DWORD, BYVAL langid AS WORD, BYREF phyphresult AS HYPHRESULT)

' // Size = 8 bytes
TYPE HYPHENATEINFO DWORD FILL
   cbSize          AS INTEGER   ' SHORT cbSize           // Size of HYPHENATEINFO structure
   dxHyphenateZone AS INTEGER   ' SHORT dxHyphenateZone  // If a space character is closer to the margin
                                '                        //  than this value, don't hyphenate (in TWIPs)
   pfnHyphenate    AS DWORD     ' void (WINAPI* pfnHyphenate)(WCHAR*, LANGID, long, HYPHRESULT*);
END TYPE

'#ifdef _WIN32
'#include <poppack.h>
'#endif

#IF NOT %DEF(%WIN32_LEAN_AND_MEAN)

' ========================================================================================
' Loads the most recent version of RichEdit installed.
' ========================================================================================
FUNCTION AfxLoadRichEditLibraryA ( _
   BYREF hRichEditLib AS DWORD, _           ' __out Handle of the RichEdit library or NULL on failure
   BYREF strClassName AS STRING _           ' __out Class name
 ) AS LONG                                  ' %TRUE or %FALSE

   IF VARPTR(hRichEditLib) = %NULL OR VARPTR(strClassName) = %NULL THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   END IF

   ' RichEdit 4.1 (Windows XP)
   hRichEditLib = LoadLibrary("MSFTEDIT.DLL")
   IF hRichEditLib THEN
      strClassName = "RichEdit50W"
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Try RichEdit 2.0 or 3.0
   hRichEditLib = LoadLibrary("RICHED20.DLL")
   IF hRichEditLib THEN
      strClassName = "RichEdit20A"
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Try RichEdit 1.0
   hRichEditLib = LoadLibrary("RICHED32.DLL")
   IF hRichEditLib THEN
      strClassName = "RichEdit"
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxLoadRichEditLibraryW ( _
   BYREF hRichEditLib AS DWORD, _           ' __out Handle of the RichEdit library or NULL on failure
   BYREF bstrClassName AS WSTRING _         ' __out Class name
 ) AS LONG                                  ' %TRUE or %FALSE

   IF VARPTR(hRichEditLib) = %NULL OR VARPTR(bstrClassName) = %NULL THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   END IF

   ' RichEdit 4.1 (Windows XP)
   hRichEditLib = LoadLibrary("MSFTEDIT.DLL")
   IF hRichEditLib THEN
      bstrClassName = "RichEdit50W"
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Try RichEdit 2.0 or 3.0
   hRichEditLib = LoadLibrary("RICHED20.DLL")
   IF hRichEditLib THEN
      bstrClassName = "RichEdit20A"
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Try RichEdit 1.0
   hRichEditLib = LoadLibrary("RICHED32.DLL")
   IF hRichEditLib THEN
      bstrClassName = "RichEdit"
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxLoadRichEditLibrary = AfxLoadRichEditLibraryW
#ELSE
   MACRO AfxLoadRichEditLibrary = AfxLoadRichEditLibraryA
#ENDIF

#ENDIF   ' #IF NOT %DEF(%WIN32_LEAN_AND_MEAN)
